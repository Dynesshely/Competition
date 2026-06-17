import type { TaskResult } from './types.js';

export interface CreateTaskRequest {
  pid: string;
  code: string;
  language: string;
  mode?: 'submit' | 'test';
}

export interface TaskResponse {
  id: string;
  pid: string;
  status: string;
  result?: TaskResult;
  error?: string;
  created_at: string;
  started_at?: string;
  completed_at?: string;
}

export interface ListTasksResponse {
  tasks: TaskResponse[];
}

export interface ApiErrorResponse {
  error: string;
  code: string;
  details?: string;
}
