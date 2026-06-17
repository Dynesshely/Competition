import { Router, Request, Response } from 'express';
import { v4 as uuidv4 } from 'uuid';
import type { CreateTaskRequest } from '@luogu-auto/shared';
import type { TaskDatabase } from '../db.js';
import type { TaskQueue } from '../queue.js';
import type { DaemonConfig } from '../config.js';

export function createTaskRouter(db: TaskDatabase, queue: TaskQueue, config: DaemonConfig): Router {
  const router = Router();

  router.post('/', (req: Request, res: Response) => {
    const body = req.body as CreateTaskRequest;

    if (!body.pid || !body.code) {
      res.status(400).json({ error: 'pid and code are required', code: 'INVALID_REQUEST' });
      return;
    }

    const now = new Date().toISOString();
    const task = {
      id: uuidv4(),
      pid: body.pid,
      code: body.code,
      language: body.language || 'cpp17',
      mode: body.mode || 'submit',
      status: 'pending' as const,
      retry_count: 0,
      max_retries: config.maxRetries,
      created_at: now,
    };

    db.insertTask(task);
    queue.enqueue(task);

    res.status(201).json({
      id: task.id,
      pid: task.pid,
      status: task.status,
      created_at: task.created_at,
    });
  });

  router.get('/', (_req: Request, res: Response) => {
    const limit = parseInt(_req.query.limit as string) || 50;
    const offset = parseInt(_req.query.offset as string) || 0;
    const tasks = db.getAllTasks(limit, offset);
    res.json({ tasks });
  });

  router.get('/:id', (req: Request, res: Response) => {
    const task = db.getTask(req.params.id as string);
    if (!task) {
      res.status(404).json({ error: 'Task not found', code: 'NOT_FOUND' });
      return;
    }
    res.json({
      id: task.id,
      pid: task.pid,
      status: task.status,
      result: task.result,
      error: task.error,
      created_at: task.created_at,
      started_at: task.started_at,
      completed_at: task.completed_at,
    });
  });

  router.delete('/:id', (req: Request, res: Response) => {
    const task = db.getTask(req.params.id as string);
    if (!task) {
      res.status(404).json({ error: 'Task not found', code: 'NOT_FOUND' });
      return;
    }
    if (task.status === 'pending' || task.status === 'queued') {
      db.updateTaskStatus(task.id, 'cancelled');
      res.json({ id: task.id, status: 'cancelled' });
    } else {
      res.status(409).json({ error: 'Task cannot be cancelled in current state', code: 'INVALID_STATE' });
    }
  });

  return router;
}
