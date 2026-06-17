import type { Task } from '@luogu-auto/shared';
import type { TaskDatabase } from './db.js';
import type { WsServerManager } from './ws-server.js';
import type { DaemonConfig } from './config.js';

export interface TaskQueue {
  enqueue(task: Task): void;
  processNext(): void;
  isExtensionOnline(): boolean;
  resetRunningTasks(): void;
}

export function createQueue(db: TaskDatabase, ws: WsServerManager, _config: DaemonConfig): TaskQueue {
  const queue: Task[] = [];
  let currentTask: Task | null = null;
  let processing = false;

  function processNext() {
    if (processing || !ws.isConnected()) return;
    if (queue.length === 0) return;

    const task = queue.shift()!;
    currentTask = task;
    processing = true;
    task.status = 'running';
    task.started_at = new Date().toISOString();
    db.updateTaskStatus(task.id, 'running');

    const sent = ws.sendTask(task.id, task.pid, task.code, task.language);
    if (!sent) {
      task.status = 'pending';
      queue.unshift(task);
      processing = false;
      currentTask = null;
      db.updateTaskStatus(task.id, 'pending');
    }
  }

  ws.onConnectionChange((connected) => {
    if (!connected && currentTask) {
      // Re-enqueue the running task instead of leaving it orphaned
      queue.unshift(currentTask);
      db.updateTaskStatus(currentTask.id, 'pending');
      currentTask = null;
      processing = false;
    }
    if (connected) {
      processNext();
    }
  });

  ws.onProgress((msg) => {
    if (currentTask && msg.taskId === currentTask.id) {
      console.log(`[${currentTask.pid}] ${msg.step}${msg.message ? ': ' + msg.message : ''}`);
    }
  });

  ws.onResult((msg) => {
    if (currentTask && msg.taskId === currentTask.id) {
      currentTask.status = 'completed';
      currentTask.result = msg.result;
      currentTask.completed_at = new Date().toISOString();
      db.updateTaskResult(currentTask.id, msg.result);
      console.log(`[${currentTask.pid}] completed: ${msg.result.verdict} (${msg.result.score})`);
      currentTask = null;
      processing = false;
      processNext();
    }
  });

  ws.onError((msg) => {
    if (currentTask && msg.taskId === currentTask.id) {
      if (currentTask.retry_count < currentTask.max_retries) {
        currentTask.retry_count++;
        db.updateTaskStatus(currentTask.id, 'pending');
        console.log(`[${currentTask.pid}] retry ${currentTask.retry_count}/${currentTask.max_retries}`);
      } else {
        currentTask.status = 'failed';
        currentTask.error = msg.message;
        currentTask.completed_at = new Date().toISOString();
        db.updateTaskError(currentTask.id, msg.message);
        console.log(`[${currentTask.pid}] failed: ${msg.message}`);
      }
      currentTask = null;
      processing = false;
      processNext();
    }
  });

  return {
    enqueue(task) {
      queue.push(task);
      db.updateTaskStatus(task.id, 'queued');
      processNext();
    },

    processNext,

    isExtensionOnline: () => ws.isConnected(),

    resetRunningTasks() {
      const running = db.getTasksByStatus('running');
      for (const t of running) {
        db.updateTaskStatus(t.id, 'pending');
      }
    },
  };
}
