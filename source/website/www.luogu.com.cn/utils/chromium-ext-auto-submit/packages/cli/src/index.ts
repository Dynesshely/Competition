#!/usr/bin/env node
import { Command } from 'commander';
import { submitCommand } from './commands/submit.js';
import { batchCommand } from './commands/batch.js';
import { installCommand } from './commands/install.js';

const program = new Command();
program
  .name('luogu-cli')
  .description('Luogu automatic code submission CLI')
  .version('0.1.0');

program
  .command('submit <file>')
  .description('Submit a single code file for Luogu evaluation')
  .option('-l, --language <lang>', 'Language (e.g. cpp17, python3)', 'cpp17')
  .option('--daemon-url <url>', 'Daemon HTTP URL')
  .action(submitCommand);

program
  .command('batch <directory>')
  .description('Batch submit all .cpp files in a directory')
  .option('--include <pattern>', 'Include pattern (regex)')
  .option('--exclude <pattern>', 'Exclude pattern (regex)')
  .option('-l, --language <lang>', 'Language (e.g. cpp17)', 'cpp17')
  .option('--daemon-url <url>', 'Daemon HTTP URL')
  .option('--export <format>', 'Export format (json|markdown)', 'markdown')
  .action(batchCommand);

program
  .command('install')
  .description('Show installation guide')
  .action(installCommand);

program.parse();
