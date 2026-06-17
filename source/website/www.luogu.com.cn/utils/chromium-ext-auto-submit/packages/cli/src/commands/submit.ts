import { readFileSync } from 'fs';
import { basename, resolve } from 'path';
import { createClient, ApiError } from '../client.js';
import { readConfig } from '../config.js';
import { showInfo, showResult, showError } from '../display.js';
import { POLL_INTERVAL_MS } from '@luogu-auto/shared';

export async function submitCommand(file: string, options: { language?: string; daemonUrl?: string }) {
  const config = readConfig({ daemonUrl: options.daemonUrl });
  const client = createClient(config.daemonUrl);

  file = resolve(file);

  let code: string;
  try {
    code = readFileSync(file, 'utf-8');
  } catch {
    showError(`File not found: ${file}`);
    process.exit(1);
  }

  const filename = basename(file);
  const match = filename.match(/^([A-Za-z]\d+)\./);
  const pid = match ? match[1].toUpperCase() : filename.replace(/\.\w+$/, '');

  const language = options.language || config.language;
  const codeBase64 = Buffer.from(code).toString('base64');

  showInfo(`Submitting ${pid} (${filename}, ${language})`);

  try {
    const health = await client.healthCheck();
    if (!health.wsConnected) {
      showError('Browser extension not connected. Make sure Chrome is running with the extension loaded.');
      process.exit(1);
    }
  } catch {
    showError(`Daemon not reachable at ${config.daemonUrl}. Make sure luogu-daemon is running.`);
    process.exit(1);
  }

  let task;
  try {
    task = await client.createTask({ pid, code: codeBase64, language });
  } catch (e) {
    if (e instanceof ApiError) {
      showError(`Failed to create task: ${e.message}`);
    } else {
      showError(`Failed to create task: ${String(e)}`);
    }
    process.exit(1);
  }

  showInfo(`Task created: ${task.id}`);

  while (true) {
    await sleep(POLL_INTERVAL_MS);
    try {
      task = await client.getTask(task.id);
    } catch {
      continue;
    }
    if (task.status === 'completed') {
      showResult(task);
      if (task.result?.verdict === 'AC') {
        process.exit(0);
      } else {
        process.exit(1);
      }
    } else if (task.status === 'failed') {
      showResult(task);
      process.exit(1);
    } else if (task.status === 'cancelled') {
      showInfo('Task cancelled');
      process.exit(0);
    } else {
      process.stdout.write('.');
    }
  }
}

function sleep(ms: number): Promise<void> {
  return new Promise(resolve => setTimeout(resolve, ms));
}
