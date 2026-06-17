import { homedir } from 'os';
import { join } from 'path';
import { DAEMON_HTTP_PORT, DAEMON_WS_PORT } from '@luogu-auto/shared';

export interface DaemonConfig {
  httpPort: number;
  wsPort: number;
  dbPath: string;
  maxConcurrency: number;
  maxRetries: number;
}

export function readConfig(): DaemonConfig {
  return {
    httpPort: Number(process.env.DAEMON_HTTP_PORT) || DAEMON_HTTP_PORT,
    wsPort: Number(process.env.DAEMON_WS_PORT) || DAEMON_WS_PORT,
    dbPath: process.env.DAEMON_DB_PATH || join(homedir(), '.local/share/luogu-daemon/tasks.db'),
    maxConcurrency: 1,
    maxRetries: 3,
  };
}
