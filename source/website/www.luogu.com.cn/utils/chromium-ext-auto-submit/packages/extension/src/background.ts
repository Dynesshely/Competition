import { DAEMON_WS_URL } from '@luogu-auto/shared';

let ws: WebSocket | null = null;
let currentTaskId: string | null = null;
let currentPid: string | null = null;
let reconnectTimer: ReturnType<typeof setTimeout> | null = null;
let connected = false;

// ========== WebSocket Connection ==========

function connect() {
  if (ws && (ws.readyState === WebSocket.OPEN || ws.readyState === WebSocket.CONNECTING)) return;

  try {
    ws = new WebSocket(DAEMON_WS_URL);
  } catch {
    scheduleReconnect();
    return;
  }

  ws.onopen = () => {
    connected = true;
    ws!.send(JSON.stringify({ type: 'register', version: chrome.runtime.getManifest().version }));
    chrome.action.setBadgeText({ text: '' });
    chrome.action.setBadgeBackgroundColor({ color: '#4CAF50' });
    if (reconnectTimer) { clearTimeout(reconnectTimer); reconnectTimer = null; }
  };

  ws.onmessage = (event) => {
    let msg: any;
    try { msg = JSON.parse(event.data); } catch { return; }
    handleDaemonMessage(msg);
  };

  ws.onclose = () => {
    connected = false;
    currentTaskId = null;
    currentPid = null;
    chrome.action.setBadgeText({ text: 'OFF' });
    chrome.action.setBadgeBackgroundColor({ color: '#F44336' });
    scheduleReconnect();
  };

  ws.onerror = () => { /* onclose handles cleanup */ };
}

function scheduleReconnect() {
  if (reconnectTimer) return;
  reconnectTimer = setTimeout(() => { reconnectTimer = null; connect(); }, 3000);
}

function handleDaemonMessage(msg: any) {
  switch (msg.type) {
    case 'dispatch_task':
      handleTask(msg.taskId, msg.pid, msg.code, msg.language);
      break;
    case 'ping':
      if (ws?.readyState === WebSocket.OPEN) ws.send(JSON.stringify({ type: 'pong' }));
      break;
  }
}

// ========== Two-Phase Task Orchestration ==========

async function handleTask(taskId: string, pid: string, code: string, language: string) {
  currentTaskId = taskId;
  currentPid = pid;
  chrome.action.setBadgeText({ text: pid });

  // --- Phase 1: Navigate to problem page, fill code, click submit ---
  const tab1 = await navigateTo(`https://www.luogu.com.cn/problem/${pid}#submit`);

  sendProgress('navigating', `Navigated to ${pid}#submit`);

  // Start listening for /record/ BEFORE sending execute_submit,
  // because the click() inside content script triggers navigation immediately.
  const recordTabPromise = waitForRecordTab(tab1.id!);

  let phase1: any;
  try {
    phase1 = await chrome.tabs.sendMessage(tab1.id!, {
      type: 'execute_submit', taskId, pid, code, language,
    });
  } catch (err: any) {
    await sendError(`Phase 1 failed: ${err.message}`);
    cleanup();
    return;
  }

  if (!phase1?.success) {
    await sendError(`Phase 1 failed: ${phase1?.error || 'unknown'}`);
    cleanup();
    return;
  }

  // --- Phase 2: Await the record tab that was already being watched ---
  sendProgress('submitting', 'Submitted, waiting for record page');

  const tab2 = await recordTabPromise;
  if (!tab2) {
    await sendError('Evaluation timed out waiting for /record/ page');
    cleanup();
    return;
  }

  // Poll for results on the /record/ page — keep trying until results appear or timeout
  sendProgress('waiting_result', 'Record page loaded, polling for results');

  let phase2: any = null;
  const pollStart = Date.now();
  const pollTimeoutMs = 60_000;

  console.log('[bg] Phase 2: polling parse_results on tab', tab2.id);
  while (Date.now() - pollStart < pollTimeoutMs) {
    try {
      phase2 = await chrome.tabs.sendMessage(tab2.id!, { type: 'parse_results' });
    } catch (e: any) {
      console.log('[bg] parse_results sendMessage failed:', e.message);
      await sleep(2000);
      continue;
    }

    if (phase2?.success) {
      console.log('[bg] parse_results success:', JSON.stringify(phase2).slice(0, 200));
      break;
    }

    // Retryable errors: not loaded yet, wrong card, etc.
    const retryable = !phase2?.error ||
      phase2?.error.includes('retry') ||
      phase2?.error.includes('not yet') ||
      phase2?.error.includes('not found') ||
      phase2?.error.includes('No test cases') ||
      phase2?.error.includes('did not load');
    if (!retryable) {
      console.log('[bg] parse_results fatal error:', phase2?.error);
      break;
    }
    console.log('[bg] parse_results not ready:', phase2?.error);
    await sleep(2000);
  }

  if (phase2?.success) {
    await sendResult({
      verdict: phase2.verdict || 'UKE',
      score: phase2.score || 0,
      time_ms: phase2.time_ms || 0,
      memory_kb: phase2.memory_kb || 0,
      subtasks: phase2.subtasks || [],
    });
  } else {
    await sendError(phase2?.error || 'Failed to parse results');
  }

  cleanup();
}

function cleanup() {
  currentTaskId = null;
  currentPid = null;
  chrome.action.setBadgeText({ text: '' });
}

// ========== Tab Helpers ==========

async function navigateTo(url: string): Promise<chrome.tabs.Tab> {
  let tab: chrome.tabs.Tab | undefined;
  const tabs = await chrome.tabs.query({ url: 'https://www.luogu.com.cn/*' });
  tab = tabs[0];

  if (tab?.id) {
    await chrome.tabs.update(tab.id, { url, active: false });
  } else {
    tab = await chrome.tabs.create({ url, active: false });
  }
  await waitForTabComplete(tab.id!);
  return tab;
}

function waitForTabComplete(tabId: number): Promise<void> {
  return new Promise((resolve) => {
    const listener = (changedTabId: number, changeInfo: chrome.tabs.TabChangeInfo) => {
      if (changedTabId === tabId && changeInfo.status === 'complete') {
        chrome.tabs.onUpdated.removeListener(listener);
        setTimeout(resolve, 2000); // extra wait for SPA + CM6 init
      }
    };
    chrome.tabs.onUpdated.addListener(listener);
  });
}

async function waitForRecordTab(tabId: number): Promise<chrome.tabs.Tab | null> {
  const deadline = Date.now() + 60_000;
  while (Date.now() < deadline) {
    try {
      const tab = await chrome.tabs.get(tabId);
      if (tab.url && tab.url.includes('/record/') && tab.status === 'complete') {
        // Small extra pause for result cards to render
        await sleep(2000);
        return tab;
      }
    } catch {
      // Tab closed or inaccessible
      return null;
    }
    await sleep(1000);
  }
  return null;
}

// ========== WS Send Helpers ==========

function sendProgress(step: string, message?: string) {
  if (ws?.readyState === WebSocket.OPEN && currentTaskId) {
    ws.send(JSON.stringify({ type: 'progress', taskId: currentTaskId, step, message }));
  }
}

async function sendResult(result: any) {
  const ready = await waitForWsReady(5000);
  if (ready && currentTaskId) {
    ws!.send(JSON.stringify({ type: 'result', taskId: currentTaskId, result }));
  } else {
    console.error('[bg] cannot send result: ws not ready or no task');
  }
}

async function sendError(message: string) {
  const ready = await waitForWsReady(5000);
  if (ready && currentTaskId) {
    ws!.send(JSON.stringify({ type: 'error', taskId: currentTaskId, message }));
  } else {
    console.error('[bg] cannot send error: ws not ready or no task');
  }
}

function waitForWsReady(timeoutMs: number): Promise<boolean> {
  const deadline = Date.now() + timeoutMs;
  return new Promise((resolve) => {
    function check() {
      if (ws?.readyState === WebSocket.OPEN && currentTaskId) {
        resolve(true);
        return;
      }
      if (Date.now() > deadline) {
        resolve(false);
        return;
      }
      setTimeout(check, 200);
    }
    check();
  });
}

// ========== Popup Status ==========

chrome.runtime.onMessage.addListener((msg, _sender, sendResponse) => {
  if (msg.type === 'get_status') {
    sendResponse({ connected, taskId: currentTaskId, pid: currentPid });
  }
  if (msg.type === 'captcha_alert') {
    chrome.notifications.create('captcha', {
      type: 'basic',
      iconUrl: 'icons/icon-48.png',
      title: 'Luogu Auto Submit',
      message: '请输入验证码 — 浏览器需要你的操作',
      priority: 2,
    });
  }
});

function sleep(ms: number): Promise<void> {
  return new Promise(resolve => setTimeout(resolve, ms));
}

// ========== Lifecycle ==========

chrome.runtime.onStartup.addListener(connect);
chrome.runtime.onInstalled.addListener((details) => {
  connect();
  if (details.reason === 'install') chrome.tabs.create({ url: 'welcome.html' });
});
connect();
