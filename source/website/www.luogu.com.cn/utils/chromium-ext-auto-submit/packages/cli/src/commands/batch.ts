import { readdirSync, readFileSync } from 'fs';
import { join, basename, resolve } from 'path';
import { createClient, ApiError } from '../client.js';
import { readConfig } from '../config.js';
import {
  showHeader, showProgress, showProgressDone,
  showMarkdownTable, showJsonExport, showError, showInfo, showWarn,
} from '../display.js';
import { POLL_INTERVAL_MS } from '@luogu-auto/shared';
import type { TaskResponse } from '@luogu-auto/shared';

export async function batchCommand(
  directory: string,
  options: { include?: string; exclude?: string; language?: string; daemonUrl?: string; export?: string },
) {
  const config = readConfig({ daemonUrl: options.daemonUrl });
  const client = createClient(config.daemonUrl);

  directory = resolve(directory);

  let files: string[];
  try {
    files = readdirSync(directory).filter(f => f.endsWith('.cpp'));
  } catch {
    showError(`Cannot read directory: ${directory}`);
    process.exit(1);
  }

  if (options.include) {
    const pattern = new RegExp(options.include);
    files = files.filter(f => pattern.test(f));
  }
  if (options.exclude) {
    const pattern = new RegExp(options.exclude);
    files = files.filter(f => !pattern.test(f));
  }

  if (files.length === 0) {
    showWarn('No .cpp files found');
    process.exit(0);
  }

  showHeader();
  showInfo(`Found ${files.length} files in ${directory}`);

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

  const results: TaskResponse[] = [];
  const language = options.language || config.language;
  const total = files.length;

  for (let i = 0; i < files.length; i++) {
    const file = files[i];
    const filePath = join(directory, file);
    const match = file.match(/^([A-Za-z]\d+)\./);
    const pid = match ? match[1].toUpperCase() : file.replace(/\.\w+$/, '');

    let code: string;
    try {
      code = readFileSync(filePath, 'utf-8');
    } catch {
      showWarn(`Skipping unreadable file: ${file}`);
      continue;
    }

    const codeBase64 = Buffer.from(code).toString('base64');

    showProgress(i + 1, total, pid, 'submitting...');

    try {
      let task = await client.createTask({ pid, code: codeBase64, language });

      while (true) {
        await sleep(POLL_INTERVAL_MS);
        try {
          task = await client.getTask(task.id);
        } catch {
          continue;
        }
        if (task.status === 'completed' || task.status === 'failed' || task.status === 'cancelled') {
          showProgressDone(i + 1, total, pid, task);
          results.push(task);
          break;
        }
      }
    } catch (e) {
      if (e instanceof ApiError) {
        showError(`Failed: ${e.message}`);
      }
    }

    // Small delay between submissions to respect rate limits
    await sleep(2000);
  }

  console.log();
  showInfo(`Done. ${results.length}/${total} tasks completed.`);

  if (results.length > 0) {
    if (options.export === 'json') {
      showJsonExport(results);
    } else {
      console.log();
      showMarkdownTable(results);
    }
  }
}

function sleep(ms: number): Promise<void> {
  return new Promise(resolve => setTimeout(resolve, ms));
}
