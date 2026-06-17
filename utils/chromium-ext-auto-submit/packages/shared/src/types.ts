export type TaskStatus =
  | 'pending'
  | 'queued'
  | 'running'
  | 'completed'
  | 'failed'
  | 'cancelled';

export type Verdict =
  | 'AC' | 'WA' | 'TLE' | 'RE' | 'MLE' | 'CE' | 'OLE' | 'UKE' | 'PENDING';

export type LanguageId = keyof typeof import('./constants.js').LANGUAGE_MAP;

export interface SubtaskResult {
  index: number;
  verdict: Verdict;
  score: number;
  time_ms: number;
  memory_kb: number;
}

export interface TaskResult {
  verdict: Verdict;
  score: number;
  time_ms: number;
  memory_kb: number;
  subtasks: SubtaskResult[];
}

export interface Task {
  id: string;
  pid: string;
  code: string;
  language: string;
  mode: 'submit' | 'test';
  status: TaskStatus;
  result?: TaskResult;
  error?: string;
  retry_count: number;
  max_retries: number;
  created_at: string;
  started_at?: string;
  completed_at?: string;
}
