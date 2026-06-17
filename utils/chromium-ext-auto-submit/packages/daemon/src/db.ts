import Database from 'better-sqlite3';
import type { Task, TaskResult, TaskStatus } from '@luogu-auto/shared';

export interface TaskDatabase {
  insertTask(task: Task): void;
  getTask(id: string): Task | undefined;
  getAllTasks(limit?: number, offset?: number): Task[];
  getTasksByStatus(status: TaskStatus): Task[];
  updateTaskStatus(id: string, status: TaskStatus): void;
  updateTaskResult(id: string, result: TaskResult): void;
  updateTaskError(id: string, error: string): void;
  close(): void;
}

export function createDatabase(dbPath: string): TaskDatabase {
  const db = new Database(dbPath);

  db.pragma('journal_mode = WAL');

  db.exec(`
    CREATE TABLE IF NOT EXISTS tasks (
      id TEXT PRIMARY KEY,
      pid TEXT NOT NULL,
      code TEXT NOT NULL,
      language TEXT NOT NULL DEFAULT 'cpp17',
      mode TEXT NOT NULL DEFAULT 'submit',
      status TEXT NOT NULL DEFAULT 'pending',
      result TEXT,
      error TEXT,
      retry_count INTEGER NOT NULL DEFAULT 0,
      max_retries INTEGER NOT NULL DEFAULT 3,
      created_at TEXT NOT NULL,
      started_at TEXT,
      completed_at TEXT
    )
  `);

  db.exec('CREATE INDEX IF NOT EXISTS idx_tasks_status ON tasks(status)');

  function rowToTask(row: any): Task {
    return {
      ...row,
      result: row.result ? JSON.parse(row.result) : undefined,
    };
  }

  return {
    insertTask(task) {
      const stmt = db.prepare(`
        INSERT INTO tasks (id, pid, code, language, mode, status, result, error, retry_count, max_retries, created_at, started_at, completed_at)
        VALUES (@id, @pid, @code, @language, @mode, @status, @result, @error, @retryCount, @maxRetries, @createdAt, @startedAt, @completedAt)
      `);
      stmt.run({
        id: task.id,
        pid: task.pid,
        code: task.code,
        language: task.language,
        mode: task.mode,
        status: task.status,
        result: task.result ? JSON.stringify(task.result) : null,
        error: task.error || null,
        retryCount: task.retry_count,
        maxRetries: task.max_retries,
        createdAt: task.created_at,
        startedAt: task.started_at || null,
        completedAt: task.completed_at || null,
      });
    },

    getTask(id) {
      const row = db.prepare('SELECT * FROM tasks WHERE id = ?').get(id) as any;
      return row ? rowToTask(row) : undefined;
    },

    getAllTasks(limit = 50, offset = 0) {
      const rows = db.prepare('SELECT * FROM tasks ORDER BY created_at DESC LIMIT ? OFFSET ?').all(limit, offset) as any[];
      return rows.map(rowToTask);
    },

    getTasksByStatus(status) {
      const rows = db.prepare('SELECT * FROM tasks WHERE status = ?').all(status) as any[];
      return rows.map(rowToTask);
    },

    updateTaskStatus(id, status) {
      db.prepare('UPDATE tasks SET status = ? WHERE id = ?').run(status, id);
    },

    updateTaskResult(id, result) {
      db.prepare('UPDATE tasks SET status = ?, result = ?, completed_at = ? WHERE id = ?')
        .run('completed', JSON.stringify(result), new Date().toISOString(), id);
    },

    updateTaskError(id, error) {
      db.prepare('UPDATE tasks SET status = ?, error = ?, completed_at = ? WHERE id = ?')
        .run('failed', error, new Date().toISOString(), id);
    },

    close() {
      db.close();
    },
  };
}
