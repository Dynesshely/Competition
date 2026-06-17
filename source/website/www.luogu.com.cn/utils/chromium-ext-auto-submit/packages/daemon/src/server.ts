import express, { type Express } from 'express';
import { createTaskRouter } from './routes/tasks.js';
import type { TaskDatabase } from './db.js';
import type { TaskQueue } from './queue.js';
import type { DaemonConfig } from './config.js';

export function createServer(db: TaskDatabase, queue: TaskQueue, config: DaemonConfig): Express {
  const app = express();
  app.use(express.json({ limit: '1mb' }));

  app.get('/api/health', (_req, res) => {
    res.json({ status: 'ok', wsConnected: queue.isExtensionOnline() });
  });

  app.use('/api/tasks', createTaskRouter(db, queue, config));

  app.use((err: Error, _req: any, res: any, _next: any) => {
    console.error('[http] error:', err.message);
    res.status(500).json({ error: err.message, code: 'INTERNAL_ERROR' });
  });

  return app;
}
