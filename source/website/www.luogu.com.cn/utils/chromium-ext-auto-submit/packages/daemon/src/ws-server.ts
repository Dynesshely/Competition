import { WebSocketServer, WebSocket } from 'ws';
import type { WsClientToServer } from '@luogu-auto/shared';
import { DAEMON_WS_PORT, PING_INTERVAL_MS } from '@luogu-auto/shared';

type ProgressHandler = (msg: any) => void;
type ResultHandler = (msg: any) => void;
type ErrorHandler = (msg: any) => void;
type ConnectionHandler = (connected: boolean) => void;

export interface WsServerManager {
  isConnected(): boolean;
  sendTask(taskId: string, pid: string, code: string, language: string): boolean;
  onProgress(cb: ProgressHandler): void;
  onResult(cb: ResultHandler): void;
  onError(cb: ErrorHandler): void;
  onConnectionChange(cb: ConnectionHandler): void;
  close(): void;
}

export function createWsServer(port: number = DAEMON_WS_PORT): WsServerManager {
  const wss = new WebSocketServer({ host: '127.0.0.1', port });
  let client: WebSocket | null = null;
  let pingTimer: ReturnType<typeof setInterval> | null = null;
  let connected = false;

  const progressCbs: ProgressHandler[] = [];
  const resultCbs: ResultHandler[] = [];
  const errorCbs: ErrorHandler[] = [];
  const connectionCbs: ConnectionHandler[] = [];

  function notifyConnectionChange(val: boolean) {
    connected = val;
    connectionCbs.forEach(cb => cb(val));
  }

  wss.on('connection', (ws) => {
    if (client) {
      ws.close(4001, 'Another extension already connected');
      return;
    }
    client = ws;
    notifyConnectionChange(true);
    console.log('[ws] extension connected');

    ws.on('message', (data) => {
      let msg: any;
      try {
        msg = JSON.parse(data.toString());
      } catch {
        return;
      }
      // Check for id field in any message — could be taskId from WsClientToServer
      const taskId = msg.taskId || msg.id;
      switch (msg.type) {
        case 'register':
          console.log(`[ws] extension registered v${msg.version}`);
          break;
        case 'progress':
          progressCbs.forEach(cb => cb(msg));
          break;
        case 'result':
          resultCbs.forEach(cb => cb(msg));
          break;
        case 'error':
          errorCbs.forEach(cb => cb(msg));
          break;
        case 'pong':
          break;
      }
    });

    ws.on('close', () => {
      client = null;
      notifyConnectionChange(false);
      console.log('[ws] extension disconnected');
    });

    ws.on('error', (err) => {
      console.error('[ws] client error:', err.message);
    });

    ws.send(JSON.stringify({ type: 'welcome', message: 'Connected to luogu-daemon' }));
  });

  pingTimer = setInterval(() => {
    if (client && client.readyState === WebSocket.OPEN) {
      client.send(JSON.stringify({ type: 'ping' }));
    }
  }, PING_INTERVAL_MS);

  return {
    isConnected: () => connected,
    sendTask(taskId, pid, code, language) {
      if (!client || client.readyState !== WebSocket.OPEN) return false;
      client.send(JSON.stringify({ type: 'dispatch_task', taskId, pid, code, language }));
      return true;
    },
    onProgress(cb) { progressCbs.push(cb); },
    onResult(cb) { resultCbs.push(cb); },
    onError(cb) { errorCbs.push(cb); },
    onConnectionChange(cb) { connectionCbs.push(cb); },
    close() {
      if (pingTimer) clearInterval(pingTimer);
      wss.close();
    },
  };
}
