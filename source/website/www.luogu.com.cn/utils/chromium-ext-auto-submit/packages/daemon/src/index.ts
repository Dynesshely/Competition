import { createServer } from './server.js';
import { createWsServer } from './ws-server.js';
import { createDatabase } from './db.js';
import { createQueue } from './queue.js';
import { readConfig } from './config.js';
import { mkdirSync } from 'fs';
import { dirname } from 'path';

async function main() {
  const config = readConfig();

  mkdirSync(dirname(config.dbPath), { recursive: true });

  const db = createDatabase(config.dbPath);
  const ws = createWsServer(config.wsPort);
  const queue = createQueue(db, ws, config);

  queue.resetRunningTasks();

  const app = createServer(db, queue, config);
  app.listen(config.httpPort, () => {
    console.log(`[daemon] HTTP server listening on http://127.0.0.1:${config.httpPort}`);
    console.log(`[daemon] WS server listening on ws://127.0.0.1:${config.wsPort}`);
    console.log(`[daemon] database: ${config.dbPath}`);
  });

  process.on('SIGINT', () => {
    console.log('[daemon] shutting down...');
    ws.close();
    db.close();
    process.exit(0);
  });

  process.on('SIGTERM', () => {
    console.log('[daemon] shutting down...');
    ws.close();
    db.close();
    process.exit(0);
  });
}

main().catch(console.error);
