// ============================================================
//  Phase 1: execute_submit — fill code + click submit
//  Phase 2: parse_results — parse /record/ page DOM
// ============================================================

interface SubmitCommand {
  type: 'execute_submit';
  taskId: string;
  pid: string;
  code: string;
  language: string;
}

interface ParseCommand {
  type: 'parse_results';
}

interface SubmitResult {
  success: boolean;
  error?: string;
  verdict?: string;
  score?: number;
  time_ms?: number;
  memory_kb?: number;
  subtasks?: Array<{
    index: number;
    verdict: string;
    score: number;
    time_ms: number;
    memory_kb: number;
  }>;
}

chrome.runtime.onMessage.addListener((msg: any, _sender, sendResponse) => {
  if (msg.type === 'execute_submit') {
    executeSubmit(msg).then(sendResponse).catch((err: Error) => sendResponse({ success: false, error: err.message }));
    return true;
  }
  if (msg.type === 'parse_results') {
    parseResults().then(sendResponse).catch((err: Error) => sendResponse({ success: false, error: err.message }));
    return true;
  }
});

// ========== Phase 1: Fill code + click submit ==========

async function executeSubmit(cmd: SubmitCommand): Promise<SubmitResult> {
  const code = atob(cmd.code);

  // Step 1: Fill code into CodeMirror 6 editor
  const cmContent = await waitForElement('.cm-content', 5000);
  if (!cmContent) {
    return { success: false, error: 'Code editor (.cm-content) not found' };
  }

  (cmContent as HTMLElement).focus();
  document.execCommand('selectAll', false);
  document.execCommand('insertText', false, code);
  await sleep(300);

  // Step 2: Select language
  await selectLanguage(cmd.language);

  // Step 3: Click submit button
  const submitBtn = findSubmitButton();
  if (!submitBtn) {
    return { success: false, error: 'Submit button not found' };
  }
  (submitBtn as HTMLElement).click();

  // Step 4: Check for captcha (SweetAlert2) modal triggered by rate-limiting
  await sleep(1000);
  const captcha = detectCaptcha();
  if (captcha) {
    console.log('[content] captcha detected, alerting user');
    // System notification (reliable, doesn't need user gesture)
    try { chrome.runtime.sendMessage({ type: 'captcha_alert' }); } catch { /* ignore */ }
    // Also try audible alert via Web Audio
    startAlertSound();

    // Wait for captcha modal to close (user submits or cancels)
    await waitForCondition(() => !detectCaptcha(), 120000);

    console.log('[content] captcha closed, continuing');
    await sleep(500);
  }

  console.log('[content] execute_submit done');
  return { success: true };
}

function detectCaptcha(): Element | null {
  const popups = document.querySelectorAll('.swal2-popup');
  for (const popup of popups) {
    const title = popup.querySelector('.swal2-title');
    if (title && title.textContent?.includes('验证码')) return popup;
  }
  return null;
}

function startAlertSound() {
  const beep = () => {
    try {
      const ctx = new AudioContext();
      ctx.resume().then(() => {
        const osc = ctx.createOscillator();
        const gain = ctx.createGain();
        osc.connect(gain);
        gain.connect(ctx.destination);
        osc.frequency.value = 880;
        osc.type = 'square';
        gain.gain.setValueAtTime(0.3, ctx.currentTime);
        gain.gain.exponentialRampToValueAtTime(0.001, ctx.currentTime + 0.3);
        osc.start(ctx.currentTime);
        osc.stop(ctx.currentTime + 0.3);
        setTimeout(() => ctx.close(), 500);
      }).catch(() => { /* autoplay blocked */ });
    } catch { /* AudioContext unavailable */ }
  };
  beep();
  return setInterval(beep, 1500);
}

function findSubmitButton(): HTMLElement | null {
  const xpath = '//*[@id="app"]/div[4]/main/div/div/div[2]/div/div[2]/button';
  const byXPath = document.evaluate(
    xpath, document, null, XPathResult.FIRST_ORDERED_NODE_TYPE, null,
  ).singleNodeValue as HTMLElement | null;
  if (byXPath) return byXPath;

  const btns = document.querySelectorAll('button');
  for (const btn of btns) {
    if (btn.textContent?.trim() === '提交评测') return btn;
  }
  for (const btn of btns) {
    if (btn.textContent?.trim().includes('提交')) return btn;
  }
  return null;
}

async function selectLanguage(lang: string) {
  const selectors = ['select[name="language"]', '.language-selector select', '[data-lang] select'];
  for (const sel of selectors) {
    const el = document.querySelector(sel) as HTMLSelectElement | null;
    if (el) {
      el.value = lang;
      el.dispatchEvent(new Event('change', { bubbles: true }));
      return;
    }
  }
}

// ========== Phase 2: Parse /record/ page ==========

function findResultCard(): Element | null {
  // Find the card that actually contains test-case wrappers (not the summary card)
  const cards = document.querySelectorAll('.card.padding-default');
  for (const card of cards) {
    if (card.querySelector('.wrapper .content .status')) return card;
  }
  return null;
}

async function parseResults(): Promise<SubmitResult> {
  console.log('[content] parseResults: waiting for result elements...');
  const ready = await waitForCondition(() => {
    const card = findResultCard();
    if (!card) return false;
    const statuses = card.querySelectorAll('.wrapper .content .status');
    if (statuses.length === 0) return false;
    for (const s of statuses) {
      const text = s.textContent?.trim() || '';
      if (text && !text.includes('Waiting') && !text.includes('Pending') && !text.includes('Judging')) {
        return true;
      }
    }
    return false;
  }, 30000);

  if (!ready) {
    console.log('[content] parseResults: timeout waiting for results');
    return { success: false, error: 'Results did not load in time' };
  }

  await sleep(500);
  const result = doParse();
  console.log(`[content] parseResults: verdict=${result.verdict} score=${result.score} subtasks=${result.subtasks?.length || 0}`);
  return result;
}

function doParse(): SubmitResult {
  const card = findResultCard();
  if (!card) {
    return { success: false, error: 'Result card not found' };
  }

  const wrappers = card.querySelectorAll('.wrapper');
  const subtasks: any[] = [];

  for (const wrapper of wrappers) {
    const statusEl = wrapper.querySelector('.content .status');
    const infoEl = wrapper.querySelector('.content .info');
    const msgEl = wrapper.querySelector('.message');
    const idEl = wrapper.querySelector('.id');

    const idText = idEl?.textContent?.trim() || '';
    const index = parseInt(idText.replace('#', '')) || subtasks.length + 1;
    const verdictRaw = statusEl?.textContent?.trim() || '';
    const info = infoEl?.textContent?.trim() || '';
    const msg = msgEl?.textContent?.trim() || '';

    subtasks.push({
      index,
      verdict: normalizeVerdict(verdictRaw),
      score: parseScoreFromMessage(msg),
      time_ms: parseTimeMs(info),
      memory_kb: parseMemoryKb(info),
    });
  }

  if (subtasks.length === 0) {
    return { success: false, error: 'No test cases found in result container' };
  }

  // Retry once if all verdicts are defaulting — DOM may not be fully painted
  if (subtasks.every(st => st.verdict === 'UKE' && st.time_ms === 0)) {
    return { success: false, error: 'Results not yet populated — retry' };
  }

  const order = ['AC', 'TLE', 'MLE', 'OLE', 'WA', 'RE', 'CE', 'UKE'];
  let worst = 'AC';
  for (const st of subtasks) {
    if (order.indexOf(st.verdict) > order.indexOf(worst)) worst = st.verdict;
  }

  return {
    success: true,
    verdict: worst,
    score: subtasks.reduce((s, t) => s + t.score, 0),
    time_ms: subtasks.reduce((m, t) => Math.max(m, t.time_ms), 0),
    memory_kb: subtasks.reduce((m, t) => Math.max(m, t.memory_kb), 0),
    subtasks,
  };
}

// ========== Helpers ==========

function waitForCondition(condition: () => boolean, timeoutMs: number): Promise<boolean> {
  return new Promise((resolve) => {
    if (condition()) { resolve(true); return; }
    const start = Date.now();
    const interval = setInterval(() => {
      if (condition()) { clearInterval(interval); resolve(true); }
      else if (Date.now() - start > timeoutMs) { clearInterval(interval); resolve(false); }
    }, 200);
  });
}

function waitForElement(selector: string, timeoutMs: number): Promise<Element | null> {
  return new Promise((resolve) => {
    const el = document.querySelector(selector);
    if (el) { resolve(el); return; }
    const start = Date.now();
    const interval = setInterval(() => {
      const el = document.querySelector(selector);
      if (el) { clearInterval(interval); resolve(el); }
      else if (Date.now() - start > timeoutMs) { clearInterval(interval); resolve(null); }
    }, 200);
  });
}

// "4ms/788.00KB" → 4
function parseTimeMs(info: string): number {
  const m = info.match(/([\d.]+)\s*ms/i);
  return m ? parseFloat(m[1]) : 0;
}

// "4ms/788.00KB" → 788 | "5ms/1.04MB" → ~1065
function parseMemoryKb(info: string): number {
  const kb = info.match(/([\d.]+)\s*KB/i);
  if (kb) return parseFloat(kb[1]);
  const mb = info.match(/([\d.]+)\s*MB/i);
  if (mb) return parseFloat(mb[1]) * 1024;
  return 0;
}

// "Accepted, 得分 10.ok accepted" → 10
function parseScoreFromMessage(msg: string): number {
  const m = msg.match(/得分\s*(\d+)/);
  return m ? parseInt(m[1]) : 0;
}

function normalizeVerdict(v: string): string {
  const u = v.toUpperCase();
  if (u.includes('AC')) return 'AC';
  if (u.includes('WA')) return 'WA';
  if (u.includes('TLE')) return 'TLE';
  if (u.includes('RE')) return 'RE';
  if (u.includes('MLE')) return 'MLE';
  if (u.includes('CE')) return 'CE';
  if (u.includes('OLE')) return 'OLE';
  return v || 'UKE';
}

function sleep(ms: number): Promise<void> {
  return new Promise(resolve => setTimeout(resolve, ms));
}
