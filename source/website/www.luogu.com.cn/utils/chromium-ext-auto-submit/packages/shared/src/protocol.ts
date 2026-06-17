import type { TaskResult } from './types.js';

export interface WsDispatchTask {
  type: 'dispatch_task';
  taskId: string;
  pid: string;
  code: string;
  language: string;
}

export interface WsPing {
  type: 'ping';
}

export interface WsWelcome {
  type: 'welcome';
  message: string;
}

export type WsServerToClient = WsDispatchTask | WsPing | WsWelcome;

export type ProgressStep =
  | 'navigating'
  | 'filling_code'
  | 'submitting'
  | 'waiting_result'
  | 'done'
  | 'error';

export interface WsProgress {
  type: 'progress';
  taskId: string;
  step: ProgressStep;
  message?: string;
}

export interface WsResult {
  type: 'result';
  taskId: string;
  result: TaskResult;
}

export interface WsPong {
  type: 'pong';
}

export interface WsError {
  type: 'error';
  taskId: string;
  message: string;
}

export interface WsRegister {
  type: 'register';
  version: string;
}

export type WsClientToServer = WsProgress | WsResult | WsPong | WsError | WsRegister;
