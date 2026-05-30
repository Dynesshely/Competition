#!/usr/bin/env python3
"""
一本通（YBT）题目爬虫
=======================
从 ybt.ssoier.cn 获取题目数据，生成结构化的 .problem.md 文件。
生成的文件与对应的 .cpp 题解放置在同一目录下。

用法:
    python ybt.py 1000              # 爬取单个题目
    python ybt.py 1000 1001 1002    # 爬取多个题目
    python ybt.py --all             # 爬取所有已有题解对应的题目
    python ybt.py --dry-run 1000    # 预览生成内容而不写入文件

依赖:
    pip install requests beautifulsoup4

注意:
    - 一本通网站为 GB2312 编码的传统 PHP 站点，需处理编码问题
    - 题目内容通过 JavaScript pshow() 动态渲染，需从 <script> 标签中提取
    - 请求频率不宜过高，建议间隔 >= 1 秒
"""

import re
import sys
import time
from datetime import datetime, timezone, timedelta
from html import unescape
from pathlib import Path

import requests

# ─── 项目路径配置 ───────────────────────────────────────────
PROJECT_ROOT = Path(__file__).resolve().parent.parent.parent  # Competition/
YBT_SOURCE_DIR = PROJECT_ROOT / "source" / "website" / "ybt.ssoier.cn"

# ─── 网络配置 ───────────────────────────────────────────────
YBT_BASE_URL = "https://ybt.ssoier.cn"
YBT_PROBLEM_URL = f"{YBT_BASE_URL}/problem_show.php"

HEADERS = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
    "Accept-Language": "zh-CN,zh;q=0.9",
}

# ─── 难度映射 ───────────────────────────────────────────────
# 一本通题目没有明确的难度字段，根据题库章节推断
# 基础篇(1-3章) → 入门, 算法篇(4-6章) → 普及, 提高篇(7-9章) → 提高
# 这里暂不自动判断，统一标为"暂无评定"，用户可后续手动调整


def fetch_ybt_problem(pid: str) -> str:
    """从一本通网站获取题目页面的 HTML 原文。

    Args:
        pid: 题目 ID（纯数字），如 "1000"

    Returns:
        HTML 字符串（已转为 UTF-8）
    """
    resp = requests.get(
        YBT_PROBLEM_URL,
        params={"pid": pid},
        headers=HEADERS,
        timeout=15,
    )
    resp.raise_for_status()

    # 一本通用的是 GB2312 编码（也可能直接是 UTF-8）
    # 尝试从响应头获取编码
    content_type = resp.headers.get("Content-Type", "")
    if "charset=utf-8" in content_type.lower():
        resp.encoding = "utf-8"
    else:
        resp.encoding = "gb2312"

    return resp.text


def parse_ybt_html(html: str, pid: str) -> dict:
    """从一本通题目页面 HTML 中提取结构化信息。

    Args:
        html: 页面 HTML 源码
        pid: 题目 ID

    Returns:
        与 luogu.parse_problem 相同结构的 dict
    """
    # ── 标题 ──
    title_match = re.search(rf"<h3>\s*{re.escape(pid)}：(.+?)\s*</h3>", html)
    title = unescape(title_match.group(1).strip()) if title_match else pid

    # ── 时间 / 内存限制 ──
    time_match = re.search(r"时间限制:\s*(\d+)\s*ms", html)
    mem_match = re.search(r"内存限制:\s*(\d+)\s*KB", html)
    time_limit_ms = int(time_match.group(1)) if time_match else 1000
    memory_limit_kb = int(mem_match.group(1)) if mem_match else 32768

    # ── 提交统计 ──
    # HTML: 提交数:<span id=zz02>452065</span> ... 通过数:<span id=zz03>270788</span>
    submit_match = re.search(r"id=zz02>(\d[\d,]*)", html)
    pass_match = re.search(r"id=zz03>(\d[\d,]*)", html)
    total_submit = int(submit_match.group(1).replace(",", "")) if submit_match else 0
    total_accepted = int(pass_match.group(1).replace(",", "")) if pass_match else 0

    # ── 内容段落（pshow 调用）──
    # 顺序: 题目描述, 输入, 输出
    pshow_matches = re.findall(r'pshow\("(.+?)"\)', html)
    description = unescape(pshow_matches[0]).strip() if len(pshow_matches) > 0 else ""
    input_format = unescape(pshow_matches[1]).strip() if len(pshow_matches) > 1 else ""
    output_format = unescape(pshow_matches[2]).strip() if len(pshow_matches) > 2 else ""

    # ── 样例 ──
    pre_matches = re.findall(r"<pre>(.+?)</pre>", html, re.DOTALL)
    sample_input = pre_matches[0].strip() if len(pre_matches) > 0 else ""
    sample_output = pre_matches[1].strip() if len(pre_matches) > 1 else ""

    samples = []
    if sample_input or sample_output:
        samples.append({"index": 1, "input": sample_input, "output": sample_output})

    # ── 构建返回结果 ──
    source_url = f"{YBT_BASE_URL}/problem_show.php?pid={pid}"

    return {
        "pid": pid,
        "title": title,
        "difficulty": "暂无评定",
        "tags": [],
        "background": "",
        "description": description,
        "input_format": input_format,
        "output_format": output_format,
        "samples": samples,
        "hint": "",
        "time_limit_ms": time_limit_ms,
        "memory_limit_kb": memory_limit_kb,
        "total_submit": total_submit,
        "total_accepted": total_accepted,
        "source_url": source_url,
    }


def format_memory(kb: int) -> str:
    """将 KB 转为人类可读的内存大小字符串。"""
    if kb >= 1048576:
        return f"{kb / 1048576:.1f} GB"
    if kb >= 1024:
        return f"{kb / 1024:.0f} MB"
    return f"{kb} KB"


_CST = timezone(timedelta(hours=8))


def _crawl_time_str() -> str:
    """返回当前北京时间字符串，用于写入爬取时间字段。"""
    return datetime.now(_CST).strftime("%Y-%m-%d %H:%M:%S")


def generate_problem_md(info: dict) -> str:
    """根据题目结构化信息生成 .problem.md 的 Markdown 内容。

    与 luogu.py 中的同名函数保持一致格式。
    """
    memory_str = format_memory(info["memory_limit_kb"])

    lines = [
        f"# {info['pid']} {info['title']}",
        "",
        "| 属性 | 值 |",
        "|------|-----|",
        f"| 题目编号 | {info['pid']} |",
        f"| 题目来源 | [一本通]({info['source_url']}) |",
        f"| 难度 | {info['difficulty']} |",
        f"| 时间限制 | {info['time_limit_ms']} ms |",
        f"| 内存限制 | {memory_str} |",
        f"| 总提交数 | {info['total_submit']} |",
        f"| 总通过数 | {info['total_accepted']} |",
        f"| 爬取时间 | {_crawl_time_str()} |",
        "",
    ]

    # 题目描述
    if info["description"]:
        lines.append("## 题目描述")
        lines.append("")
        lines.append(info["description"])
        lines.append("")

    # 输入格式
    if info["input_format"]:
        lines.append("## 输入格式")
        lines.append("")
        lines.append(info["input_format"])
        lines.append("")

    # 输出格式
    if info["output_format"]:
        lines.append("## 输出格式")
        lines.append("")
        lines.append(info["output_format"])
        lines.append("")

    # 样例
    if info["samples"]:
        for s in info["samples"]:
            lines.append(f"## 样例 #{s['index']}")
            lines.append("")
            lines.append("### 样例输入")
            lines.append("")
            lines.append("```")
            lines.append(s["input"])
            lines.append("```")
            lines.append("")
            lines.append("### 样例输出")
            lines.append("")
            lines.append("```")
            lines.append(s["output"])
            lines.append("```")
            lines.append("")

    # 提示
    if info["hint"]:
        lines.append("## 提示")
        lines.append("")
        lines.append(info["hint"])
        lines.append("")

    return "\n".join(lines)


def get_existing_ybt_problems() -> list[str]:
    """扫描 source/website/ybt.ssoier.cn/ 目录，提取所有已有 .cpp 解答的题目 ID。

    Returns:
        题目 ID 列表（如 ["1000", "1001"]），已去重排序
    """
    if not YBT_SOURCE_DIR.exists():
        print(f"[WARN] 目录不存在: {YBT_SOURCE_DIR}")
        return []

    pids = set()
    for f in YBT_SOURCE_DIR.iterdir():
        if not f.is_file() or not f.suffix == ".cpp":
            continue
        # 匹配纯数字文件名，如 1000.cpp, 1351-1.cpp
        m = re.match(r"^(\d+)", f.name)
        if m:
            pids.add(m.group(1))

    return sorted(pids, key=lambda x: int(x))


def run_single(pid: str, dry_run: bool = False) -> bool:
    """爬取单个题目并生成 .problem.md。

    Args:
        pid: 题目 ID
        dry_run: 为 True 时只打印不写文件

    Returns:
        是否成功
    """
    print(f"[INFO] 正在获取 YBT-{pid} ...", end=" ", flush=True)

    try:
        html = fetch_ybt_problem(pid)
        info = parse_ybt_html(html, pid)
    except Exception as e:
        print(f"失败: {e}")
        return False

    print(f"成功 ({info['title']})")

    md_content = generate_problem_md(info)

    if dry_run:
        print(f"[DRY-RUN] 将生成 {pid}.problem.md ({len(md_content)} 字符)")
        print("─" * 60)
        print(md_content[:1500])
        if len(md_content) > 1500:
            print(f"... (共 {len(md_content)} 字符，已截断)")
        print("─" * 60)
        return True

    # 写入文件
    out_path = YBT_SOURCE_DIR / f"{pid}.problem.md"
    out_path.write_text(md_content, encoding="utf-8")
    print(f"[OK] 已写入: {out_path}")
    return True


def main():
    import argparse

    parser = argparse.ArgumentParser(
        description="一本通题目爬虫 — 从 ybt.ssoier.cn 获取题目数据，生成 .problem.md",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
示例:
  python ybt.py 1000              # 爬取单个题目
  python ybt.py 1000 1001 1002    # 批量爬取
  python ybt.py --all             # 爬取所有已有题解对应的题目
  python ybt.py --dry-run 1000    # 预览不写入
        """,
    )
    parser.add_argument("pids", nargs="*", help="题目 ID 列表（纯数字，如 1000 1001）")
    parser.add_argument("--all", action="store_true", help="爬取所有已有 .cpp 解答的题目")
    parser.add_argument("--dry-run", action="store_true", help="仅预览，不写入文件")

    args = parser.parse_args()

    # 确定要爬取的题目列表
    if args.all:
        pids = get_existing_ybt_problems()
        if not pids:
            print("[ERROR] 未找到任何已有 .cpp 解答的一本通题目")
            sys.exit(1)
        print(f"[INFO] 发现 {len(pids)} 个已有题解的一本通题目")
    elif args.pids:
        pids = args.pids
    else:
        parser.print_help()
        sys.exit(1)

    # 逐个爬取
    success = 0
    fail = 0
    for i, pid in enumerate(pids):
        if i > 0:
            time.sleep(1.0)  # 一本通网站较老，请求间隔长一些
        if run_single(pid, dry_run=args.dry_run):
            success += 1
        else:
            fail += 1

    print(f"\n[DONE] 成功 {success}, 失败 {fail}, 总计 {len(pids)}")


if __name__ == "__main__":
    main()
