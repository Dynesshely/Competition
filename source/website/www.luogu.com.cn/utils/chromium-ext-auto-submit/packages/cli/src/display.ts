import type { TaskResponse } from '@luogu-auto/shared';

const RESET = '\x1b[0m';
const GREEN = '\x1b[32m';
const RED = '\x1b[31m';
const YELLOW = '\x1b[33m';
const BLUE = '\x1b[34m';
const CYAN = '\x1b[36m';
const GRAY = '\x1b[90m';
const BOLD = '\x1b[1m';

function verdictColor(v: string | undefined): string {
  if (!v) return GRAY;
  switch (v.toUpperCase()) {
    case 'AC': return GREEN;
    case 'WA':
    case 'RE':
    case 'CE': return RED;
    case 'TLE':
    case 'MLE':
    case 'OLE': return YELLOW;
    default: return GRAY;
  }
}

export function showHeader() {
  console.log(`${CYAN}${BOLD}Luogu Auto Submit CLI v0.1.0${RESET}\n`);
}

export function showProgress(current: number, total: number, pid: string, status: string) {
  const bar = `[${current}/${total}]`;
  process.stdout.write(`\r${BLUE}${bar}${RESET} ${BOLD}${pid}${RESET}: ${status}    `);
}

export function showProgressDone(current: number, total: number, pid: string, task: TaskResponse) {
  const bar = `[${current}/${total}]`;
  const v = task.result?.verdict ?? '?';
  const score = task.result?.score ?? 0;
  const vc = verdictColor(v);
  process.stdout.write(`\r${BLUE}${bar}${RESET} ${BOLD}${pid}${RESET}: ${vc}${v}${RESET} (${score})    \n`);
}

export function showResult(task: TaskResponse) {
  const v = task.result?.verdict ?? '?';
  const vc = verdictColor(v);
  console.log(`\n${BOLD}PID:${RESET}     ${task.pid}`);
  console.log(`${BOLD}Status:${RESET}  ${vc}${v}${RESET}`);
  if (task.result) {
    console.log(`${BOLD}Score:${RESET}   ${task.result.score}`);
    console.log(`${BOLD}Time:${RESET}    ${task.result.time_ms}ms`);
    console.log(`${BOLD}Memory:${RESET}  ${task.result.memory_kb}KB`);
    if (task.result.subtasks.length > 0) {
      console.log(`\n${BOLD}Subtasks:${RESET}`);
      for (const st of task.result.subtasks) {
        const svc = verdictColor(st.verdict);
        console.log(`  #${st.index}: ${svc}${st.verdict}${RESET} score=${st.score} time=${st.time_ms}ms mem=${st.memory_kb}KB`);
      }
    }
  }
  if (task.error) {
    console.log(`${BOLD}Error:${RESET}   ${RED}${task.error}${RESET}`);
  }
  console.log();
}

export function showMarkdownTable(tasks: TaskResponse[]) {
  console.log('| # | PID | Verdict | Score | Time | Memory |');
  console.log('|---|-----|---------|-------|------|--------|');
  for (let i = 0; i < tasks.length; i++) {
    const t = tasks[i];
    const v = t.result?.verdict ?? (t.status === 'failed' ? 'FAIL' : '?');
    const score = t.result?.score ?? 0;
    const time = t.result?.time_ms ?? 0;
    const mem = t.result?.memory_kb ?? 0;
    console.log(`| ${i + 1} | ${t.pid} | ${v} | ${score} | ${time}ms | ${mem}KB |`);
  }
}

export function showJsonExport(tasks: TaskResponse[]) {
  console.log(JSON.stringify(tasks, null, 2));
}

export function showError(message: string) {
  console.error(`${RED}[ERROR]${RESET} ${message}`);
}

export function showInfo(message: string) {
  console.log(`${BLUE}[INFO]${RESET} ${message}`);
}

export function showWarn(message: string) {
  console.log(`${YELLOW}[WARN]${RESET} ${message}`);
}
