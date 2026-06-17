import * as esbuild from 'esbuild';
import { copyFileSync, mkdirSync, existsSync, readdirSync, writeFileSync } from 'fs';
import { resolve, dirname } from 'path';
import { fileURLToPath } from 'url';
import { deflateSync } from 'zlib';

const __dirname = dirname(fileURLToPath(import.meta.url));
const src = resolve(__dirname, 'src');
const dist = resolve(__dirname, 'dist');
const watchMode = process.argv.includes('--watch');

mkdirSync(dist, { recursive: true });

const iconsDir = resolve(__dirname, 'icons');
if (!existsSync(iconsDir)) {
  mkdirSync(iconsDir, { recursive: true });
  for (const size of [16, 48, 128]) {
    const png = createMinimalPNG(size, size);
    writeFileSync(resolve(iconsDir, `icon-${size}.png`), png);
  }
  console.log('  generated: placeholder icons');
}

async function buildFile(entry, outfile, opts = {}) {
  const config = {
    entryPoints: [resolve(src, entry)],
    bundle: true,
    outfile: resolve(dist, outfile),
    platform: 'browser',
    target: 'esnext',
    minify: false,
    sourcemap: false,
    ...opts,
  };

  if (watchMode) {
    const ctx = await esbuild.context(config);
    await ctx.watch();
    console.log(`  watching: ${entry} -> ${outfile}`);
  } else {
    await esbuild.build(config);
    console.log(`  built: ${entry} -> ${outfile}`);
  }
}

async function main() {
  console.log('Building extension...');

  await buildFile('background.ts', 'background.js', { format: 'esm' });
  await buildFile('content.ts', 'content.js', { format: 'iife' });

  const staticFiles = ['manifest.json', 'popup.html', 'welcome.html', 'popup.js', 'welcome.js'];
  for (const file of staticFiles) {
    const srcPath = resolve(src, file);
    if (existsSync(srcPath)) {
      copyFileSync(srcPath, resolve(dist, file));
      console.log(`  copied: ${file}`);
    }
  }

  mkdirSync(resolve(dist, 'icons'), { recursive: true });
  for (const file of readdirSync(iconsDir)) {
    copyFileSync(resolve(iconsDir, file), resolve(dist, 'icons', file));
  }
  console.log('  copied: icons/');

  if (!watchMode) {
    console.log(`Extension built: ${dist}`);
  }
}

function createChunk(type, data) {
  const length = Buffer.alloc(4);
  length.writeUInt32BE(data.length, 0);
  const typeBuffer = Buffer.from(type, 'ascii');
  const crcData = Buffer.concat([typeBuffer, data]);

  let crc = 0xFFFFFFFF;
  for (const byte of crcData) {
    crc ^= byte;
    for (let i = 0; i < 8; i++) {
      crc = (crc >>> 1) ^ (crc & 1 ? 0xEDB88320 : 0);
    }
  }
  crc = (crc ^ 0xFFFFFFFF) >>> 0;

  const crcBuffer = Buffer.alloc(4);
  crcBuffer.writeUInt32BE(crc, 0);

  return Buffer.concat([length, typeBuffer, data, crcBuffer]);
}

function createMinimalPNG(width, height) {
  const signature = Buffer.from([137, 80, 78, 71, 13, 10, 26, 10]);

  const ihdrData = Buffer.alloc(13);
  ihdrData.writeUInt32BE(width, 0);
  ihdrData.writeUInt32BE(height, 4);
  ihdrData[8] = 8;
  ihdrData[9] = 2;
  ihdrData[10] = 0;
  ihdrData[11] = 0;
  ihdrData[12] = 0;

  const rawRows = [];
  for (let y = 0; y < height; y++) {
    const row = Buffer.alloc(1 + width * 3);
    row[0] = 0;
    for (let x = 0; x < width; x++) {
      const off = 1 + x * 3;
      row[off] = 52;
      row[off + 1] = 152;
      row[off + 2] = 219;
    }
    rawRows.push(row);
  }
  const rawData = Buffer.concat(rawRows);
  const compressed = deflateSync(rawData);

  return Buffer.concat([
    signature,
    createChunk('IHDR', ihdrData),
    createChunk('IDAT', compressed),
    createChunk('IEND', Buffer.alloc(0)),
  ]);
}

main().catch((err) => {
  console.error('Build failed:', err);
  process.exit(1);
});
