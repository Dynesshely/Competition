import { readFileSync, existsSync } from 'fs';
import { join } from 'path';
import { homedir } from 'os';
import { DAEMON_HTTP_URL } from '@luogu-auto/shared';

export interface CliConfig {
  daemonUrl: string;
  language: string;
  maxRetries: number;
}

const DEFAULT_CONFIG: CliConfig = {
  daemonUrl: DAEMON_HTTP_URL,
  language: 'cpp17',
  maxRetries: 3,
};

export function readConfig(overrides?: Partial<CliConfig>): CliConfig {
  const configPath = join(homedir(), '.config/luogu-cli/config.json');
  let fileConfig: Partial<CliConfig> = {};
  if (existsSync(configPath)) {
    try {
      fileConfig = JSON.parse(readFileSync(configPath, 'utf-8'));
    } catch {
      // ignore parse errors, use defaults
    }
  }
  // Strip undefined values from overrides so they don't overwrite defaults
  const cleanOverrides: Partial<CliConfig> = {};
  if (overrides) {
    for (const [k, v] of Object.entries(overrides)) {
      if (v !== undefined) (cleanOverrides as any)[k] = v;
    }
  }
  return { ...DEFAULT_CONFIG, ...fileConfig, ...cleanOverrides };
}
