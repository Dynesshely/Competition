/// <reference types="vite-plugin-monkey/client" />

type ProblemStatus = 'ac' | 'failed' | 'undone'

interface ProblemInfo {
  pid: string
  status: ProblemStatus
}

interface ProblemGroups {
  ac: ProblemInfo[]
  failed: ProblemInfo[]
  undone: ProblemInfo[]
}

// ========== Styles ==========

function injectStyles(): void {
  const style = document.createElement('style')
  style.textContent = `
#lh-fab {
  position: fixed;
  bottom: 28px;
  right: 28px;
  width: 44px;
  height: 44px;
  border-radius: 50%;
  background: #3498db;
  color: #fff;
  border: none;
  cursor: pointer;
  z-index: 99999;
  display: flex;
  align-items: center;
  justify-content: center;
  font-size: 18px;
  box-shadow: 0 2px 10px rgba(0,0,0,.25);
  transition: transform .2s, background .2s, box-shadow .2s;
  user-select: none;
  padding: 0;
}
#lh-fab:hover {
  transform: scale(1.08);
  background: #2980b9;
  box-shadow: 0 4px 14px rgba(0,0,0,.3);
}
#lh-fab:active {
  transform: scale(.95);
}

#lh-panel {
  position: fixed;
  bottom: 84px;
  right: 28px;
  width: 380px;
  max-height: 55vh;
  background: #fff;
  border-radius: 12px;
  box-shadow: 0 4px 20px rgba(0,0,0,.18);
  z-index: 99998;
  display: none;
  flex-direction: column;
  overflow: hidden;
  font-family: -apple-system,BlinkMacSystemFont,'Segoe UI',Roboto,sans-serif;
  font-size: 14px;
  color: #333;
}
#lh-panel.show {
  display: flex;
}

#lh-panel .lh-panel-hd {
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 14px 16px;
  font-weight: 600;
  font-size: 15px;
  border-bottom: 1px solid #eee;
  flex-shrink: 0;
}
#lh-panel .lh-panel-close {
  width: 24px;
  height: 24px;
  border: none;
  background: none;
  cursor: pointer;
  font-size: 16px;
  color: #999;
  display: flex;
  align-items: center;
  justify-content: center;
  border-radius: 4px;
  padding: 0;
}
#lh-panel .lh-panel-close:hover {
  background: #f0f0f0;
  color: #333;
}

#lh-panel .lh-panel-body {
  overflow-y: auto;
  flex: 1;
}

#lh-panel .lh-section {
  padding: 10px 16px;
}
#lh-panel .lh-section + .lh-section {
  border-top: 1px solid #f0f0f0;
}

#lh-panel .lh-sec-hd {
  display: flex;
  align-items: center;
  justify-content: space-between;
  margin-bottom: 6px;
}
#lh-panel .lh-sec-title {
  font-weight: 600;
  font-size: 13px;
  display: flex;
  align-items: center;
  gap: 6px;
  white-space: nowrap;
}
#lh-panel .lh-dot {
  width: 8px;
  height: 8px;
  border-radius: 50%;
  flex-shrink: 0;
}
#lh-panel .lh-dot.ac  { background: #27ae60; }
#lh-panel .lh-dot.wa  { background: #e74c3c; }
#lh-panel .lh-dot.ud  { background: #95a5a6; }

#lh-panel .lh-copy {
  font-size: 11px;
  padding: 3px 10px;
  border: 1px solid #ddd;
  border-radius: 4px;
  background: #fafafa;
  cursor: pointer;
  color: #888;
  transition: all .15s;
  white-space: nowrap;
  flex-shrink: 0;
}
#lh-panel .lh-copy:hover {
  background: #eee;
  border-color: #ccc;
  color: #555;
}
#lh-panel .lh-copy.ok {
  background: #27ae60;
  color: #fff;
  border-color: #27ae60;
}

#lh-panel .lh-pids {
  color: #555;
  line-height: 1.7;
  word-break: break-all;
  font-size: 13px;
  font-family: 'Consolas','Source Code Pro',monospace;
}
#lh-panel .lh-empty {
  color: #bbb;
  font-style: italic;
  font-size: 12px;
}
`
  document.head.appendChild(style)
}

// ========== Row Parsing ==========

function findRowWrap(): Element | null {
  const sel = '.row-wrap'
  const byClass = document.querySelector(sel)
  if (byClass) return byClass

  const xpath =
    '/html/body/div[1]/div[4]/main/div/div/div/div[2]/div/div[1]/div[2]'
  const byXPath = document.evaluate(
    xpath,
    document,
    null,
    XPathResult.FIRST_ORDERED_NODE_TYPE,
    null,
  ).singleNodeValue as Element | null
  return byXPath
}

function parseStatus(row: Element): ProblemStatus {
  const svg = row.querySelector('.status svg')
  if (!svg) return 'undone'
  const icon = svg.getAttribute('data-icon')
  if (icon === 'check') return 'ac'
  if (icon === 'xmark') return 'failed'
  return 'undone'
}

function parsePid(row: Element): string {
  return row.querySelector('.pid')?.textContent?.trim() ?? ''
}

function collectProblems(): ProblemGroups {
  const groups: ProblemGroups = { ac: [], failed: [], undone: [] }

  const rowWrap = findRowWrap()
  if (!rowWrap) return groups

  const rows = rowWrap.querySelectorAll(':scope > .row')
  for (const row of rows) {
    const pid = parsePid(row)
    if (!pid) continue
    const status = parseStatus(row)
    groups[status].push({ pid, status })
  }

  return groups
}

// ========== UI ==========

let fabEl: HTMLElement | null = null
let panelEl: HTMLElement | null = null
let panelVisible = false

function hidePanel(): void {
  panelVisible = false
  panelEl?.classList.remove('show')
}

function showPanel(): void {
  if (!panelEl) return
  const groups = collectProblems()
  renderPanelContent(panelEl, groups)
  panelVisible = true
  panelEl.classList.add('show')
}

function togglePanel(): void {
  if (panelVisible) {
    hidePanel()
  } else {
    showPanel()
  }
}

function buildSection(
  status: ProblemStatus,
  label: string,
  colorClass: string,
  pids: string[],
): string {
  const n = pids.length
  const joined = pids.join(', ')
  const has = n > 0

  return `
<div class="lh-section">
  <div class="lh-sec-hd">
    <span class="lh-sec-title">
      <span class="lh-dot ${colorClass}"></span>${label} (${n})
    </span>
    ${has ? `<button class="lh-copy" data-pids="${escapeAttr(joined)}">复制</button>` : ''}
  </div>
  <div class="lh-pids">${has ? joined : '<span class="lh-empty">暂无</span>'}</div>
</div>`
}

function escapeAttr(s: string): string {
  return s.replace(/&/g, '&amp;').replace(/"/g, '&quot;')
}

function renderPanelContent(panel: HTMLElement, groups: ProblemGroups): void {
  const acPids = groups.ac.map((p) => p.pid)
  const failedPids = groups.failed.map((p) => p.pid)
  const undonePids = groups.undone.map((p) => p.pid)
  const total = acPids.length + failedPids.length + undonePids.length

  panel.innerHTML = `
<div class="lh-panel-hd">
  <span>题目统计（共 ${total} 题）</span>
  <button class="lh-panel-close" title="关闭">✕</button>
</div>
<div class="lh-panel-body">
  ${buildSection('ac', '已通过', 'ac', acPids)}
  ${buildSection('failed', '未通过', 'wa', failedPids)}
  ${buildSection('undone', '未做', 'ud', undonePids)}
</div>`

  const closeBtn = panel.querySelector('.lh-panel-close')
  closeBtn?.addEventListener('click', hidePanel)

  panel.querySelectorAll('.lh-copy').forEach((btn) => {
    btn.addEventListener('click', () => {
      const pids = (btn as HTMLElement).dataset.pids ?? ''
      navigator.clipboard.writeText(pids).then(() => {
        btn.classList.add('ok')
        btn.textContent = '已复制!'
        setTimeout(() => {
          btn.classList.remove('ok')
          btn.textContent = '复制'
        }, 1500)
      }).catch(() => {
        btn.textContent = '失败'
        setTimeout(() => {
          btn.textContent = '复制'
        }, 1000)
      })
    })
  })
}

function createUI(): void {
  fabEl = document.createElement('button')
  fabEl.id = 'lh-fab'
  fabEl.innerHTML =
    '<svg viewBox="0 0 24 24" width="20" height="20" fill="none" stroke="currentColor" stroke-width="2"><path d="M3 3v18h18"/><path d="M7 16l4-8 4 4 4-6"/></svg>'
  fabEl.title = '题目统计'

  panelEl = document.createElement('div')
  panelEl.id = 'lh-panel'

  fabEl.addEventListener('click', togglePanel)

  document.addEventListener('click', (e) => {
    if (!panelVisible) return
    const t = e.target as Node
    if (!fabEl?.contains(t) && !panelEl?.contains(t)) {
      hidePanel()
    }
  })

  document.body.appendChild(fabEl)
  document.body.appendChild(panelEl)
}

function removeUI(): void {
  fabEl?.remove()
  fabEl = null
  panelEl?.remove()
  panelEl = null
  panelVisible = false
}

// ========== SPA ==========

function isListPage(): boolean {
  return /^\/problem\/list(\?|$)/.test(window.location.pathname + window.location.search) ||
    window.location.pathname === '/problem/list'
}

function handleRoute(): void {
  if (isListPage()) {
    if (!fabEl || !document.body.contains(fabEl)) {
      createUI()
    }
  } else {
    removeUI()
  }
}

function patchHistory(fn: Function): Function {
  return function (this: unknown, ...args: unknown[]) {
    const result = fn.apply(this, args)
    setTimeout(handleRoute, 80)
    return result
  }
}

function setupSPA(): void {
  history.pushState = patchHistory(history.pushState) as typeof history.pushState
  history.replaceState = patchHistory(history.replaceState) as typeof history.replaceState
  window.addEventListener('popstate', () => setTimeout(handleRoute, 80))
}

// ========== Entry ==========

function main(): void {
  injectStyles()
  setupSPA()
  handleRoute()
}

main()
