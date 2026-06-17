import type { CreateTaskRequest, TaskResponse, ListTasksResponse, ApiErrorResponse } from '@luogu-auto/shared';

export class ApiError extends Error {
  constructor(public response: ApiErrorResponse) {
    super(response.error);
    this.name = 'ApiError';
  }
}

export function createClient(baseUrl: string) {
  async function createTask(req: CreateTaskRequest): Promise<TaskResponse> {
    const res = await fetch(`${baseUrl}/api/tasks`, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify(req),
    });
    if (!res.ok) throw new ApiError(await res.json() as ApiErrorResponse);
    return res.json() as Promise<TaskResponse>;
  }

  async function getTask(id: string): Promise<TaskResponse> {
    const res = await fetch(`${baseUrl}/api/tasks/${id}`);
    if (!res.ok) throw new ApiError(await res.json() as ApiErrorResponse);
    return res.json() as Promise<TaskResponse>;
  }

  async function listTasks(limit = 50): Promise<ListTasksResponse> {
    const res = await fetch(`${baseUrl}/api/tasks?limit=${limit}`);
    return res.json() as Promise<ListTasksResponse>;
  }

  async function deleteTask(id: string): Promise<void> {
    await fetch(`${baseUrl}/api/tasks/${id}`, { method: 'DELETE' });
  }

  async function healthCheck(): Promise<{ status: string; wsConnected: boolean }> {
    const res = await fetch(`${baseUrl}/api/health`);
    return res.json() as Promise<{ status: string; wsConnected: boolean }>;
  }

  return { createTask, getTask, listTasks, deleteTask, healthCheck };
}
