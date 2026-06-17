export const DAEMON_HTTP_PORT = 9527;
export const DAEMON_WS_PORT = 9528;
export const DAEMON_HOST = '127.0.0.1';

export const DAEMON_HTTP_URL = `http://${DAEMON_HOST}:${DAEMON_HTTP_PORT}`;
export const DAEMON_WS_URL = `ws://${DAEMON_HOST}:${DAEMON_WS_PORT}`;

export const LANGUAGE_MAP = {
  cpp17: 'C++17 (GCC 12)',
  cpp14: 'C++14 (GCC 12)',
  cpp11: 'C++11 (GCC 12)',
  cpp: 'C++ (GCC 12)',
  python3: 'Python 3',
  java: 'Java',
} as const;

export const PING_INTERVAL_MS = 10_000;
export const PONG_TIMEOUT_MS = 5_000;
export const POLL_INTERVAL_MS = 1_000;
export const DEFAULT_MAX_RETRIES = 3;
