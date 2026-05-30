#!/usr/bin/env python3
"""
构建辅助 — 拷贝题目资源到 public/_gen/ 目录
=========================================
在 pnpm build 前自动执行，将 source/ 下的代码、题目、题解文件
原样拷贝到 public/_gen/assets/，供前端客户端请求使用。

用法:
    python scripts/copy_assets.py
"""

import shutil
import sys
from pathlib import Path

# ─── 路径配置 ───────────────────────────────────────────────
SCRIPT_DIR = Path(__file__).resolve().parent   # website/scripts/
WEBSITE_DIR = SCRIPT_DIR.parent                # website/
PROJECT_ROOT = WEBSITE_DIR.parent              # Competition/
SOURCE_DIR = PROJECT_ROOT / "source"
PUBLIC_DIR = WEBSITE_DIR / "public"
GEN_DIR = PUBLIC_DIR / "_gen"                  # 所有生成文件集中在此
ASSETS_DIR = GEN_DIR / "assets"

# 需要拷贝的文件后缀
COPY_EXTENSIONS = {".cpp", ".c", ".pas", ".java", ".py",
                   ".problem.md", ".explain.md", ".json"}


def copy_assets() -> None:
    """将 source/ 目录下的代码和文档文件拷贝到 public/_gen/assets/。"""
    # 清理旧的 _gen 目录
    if GEN_DIR.exists():
        shutil.rmtree(GEN_DIR)

    ASSETS_DIR.mkdir(parents=True, exist_ok=True)

    count = 0
    for src_file in SOURCE_DIR.rglob("*"):
        if not src_file.is_file():
            continue
        # suffix 只返回最后一个后缀，用 suffixes 处理 .problem.md 等复合后缀
        full_suffix = "".join(src_file.suffixes)
        if full_suffix not in COPY_EXTENSIONS:
            continue

        rel = src_file.relative_to(SOURCE_DIR)
        dst = ASSETS_DIR / rel
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src_file, dst)
        count += 1

    # 同时拷贝 index.json 到 _gen/
    index_src = WEBSITE_DIR / "index.json"
    if index_src.exists():
        shutil.copy2(index_src, GEN_DIR / "index.json")

    print(f"[copy_assets] 已拷贝 {count} 个文件 → {ASSETS_DIR.relative_to(PROJECT_ROOT)}")
    print(f"[copy_assets] index.json → {GEN_DIR.relative_to(PROJECT_ROOT)}")


if __name__ == "__main__":
    copy_assets()
