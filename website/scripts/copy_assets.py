#!/usr/bin/env python3
"""
构建辅助 — 拷贝题目资源到 public/_gen/ 目录 (增量)
==================================================
在 pnpm build/dev 前自动执行，将 source/ 下的代码、题目、题解文件
原样拷贝到 public/_gen/assets/。仅拷贝有变更的文件，跳过已是最新的。

用法:
    python scripts/copy_assets.py            # 增量拷贝
    python scripts/copy_assets.py --force    # 强制全量
"""

import argparse
import shutil
import sys
from pathlib import Path

# ─── 路径配置 ───────────────────────────────────────────────
SCRIPT_DIR = Path(__file__).resolve().parent   # website/scripts/
WEBSITE_DIR = SCRIPT_DIR.parent                # website/
PROJECT_ROOT = WEBSITE_DIR.parent              # Competition/
SOURCE_DIR = PROJECT_ROOT / "source"
PUBLIC_DIR = WEBSITE_DIR / "public"
GEN_DIR = PUBLIC_DIR / "_gen"
ASSETS_DIR = GEN_DIR / "assets"

COPY_EXTENSIONS = {".cpp", ".c", ".pas", ".java", ".py",
                   ".problem.md", ".explain.md", ".json"}


def needs_copy(src: Path, dst: Path) -> bool:
    """检查源文件是否需要拷贝到目标。"""
    if not dst.exists():
        return True
    if not dst.is_file():
        return True
    # 比较修改时间：WSL 跨文件系统 mtime 亚秒可能截断，加 1s 容差
    return src.stat().st_mtime - dst.stat().st_mtime > 1.0


def copy_assets(force: bool = False) -> None:
    """增量拷贝 source/ → public/_gen/assets/。"""
    ASSETS_DIR.mkdir(parents=True, exist_ok=True)

    copied = 0
    skipped = 0
    dst_paths = set()  # 记录所有目标路径，用于清理孤文件

    for src_file in SOURCE_DIR.rglob("*"):
        if not src_file.is_file():
            continue

        full_suffix = "".join(src_file.suffixes)
        if full_suffix not in COPY_EXTENSIONS:
            continue

        rel = src_file.relative_to(SOURCE_DIR)
        dst = ASSETS_DIR / rel
        dst_paths.add(dst)

        if not force and not needs_copy(src_file, dst):
            skipped += 1
            continue

        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src_file, dst)
        copied += 1

    # 清理目标目录中不存在于源目录的孤文件
    cleaned = 0
    for dst_file in ASSETS_DIR.rglob("*"):
        if dst_file.is_file() and dst_file not in dst_paths:
            dst_file.unlink()
            cleaned += 1

    # 删除空目录
    for d in sorted(ASSETS_DIR.rglob("*"), key=lambda p: -len(str(p))):
        if d.is_dir() and not any(d.iterdir()):
            d.rmdir()

    # ── index.json ──
    index_src = WEBSITE_DIR / "index.json"
    index_dst = GEN_DIR / "index.json"
    index_copied = 0
    if index_src.exists():
        if force or needs_copy(index_src, index_dst):
            shutil.copy2(index_src, index_dst)
            index_copied = 1

    tag = "[force]" if force else "[incr]"
    print(f"{tag} 拷贝 {copied} 个, 跳过 {skipped} 个, 清理 {cleaned} 个孤文件 → {ASSETS_DIR.relative_to(PROJECT_ROOT)}")
    if index_copied:
        print(f"{tag} index.json → {GEN_DIR.relative_to(PROJECT_ROOT)}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="增量拷贝题目资源到 public/_gen/")
    parser.add_argument("--force", "-f", action="store_true", help="强制全量拷贝")
    args = parser.parse_args()
    copy_assets(force=args.force)
