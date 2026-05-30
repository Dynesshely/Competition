/**
 * 索引加载器 — 加载 /_gen/index.json 并缓存
 * @returns {Promise<Object>}
 */

let _indexCache = null;

export async function loadIndex() {
  if (_indexCache) return _indexCache;
  const base = import.meta.env.BASE_URL;
  const resp = await fetch(`${base}_gen/index.json`);
  if (!resp.ok) throw new Error(`Failed to load index: ${resp.status}`);
  _indexCache = await resp.json();
  return _indexCache;
}

/** 使缓存失效（用于热更新场景） */
export function clearIndexCache() {
  _indexCache = null;
}
