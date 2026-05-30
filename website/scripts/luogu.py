#!/usr/bin/env python3
"""
洛谷（Luogu）题目爬虫
=======================
从洛谷 API 获取题目数据，生成结构化的 .problem.md 文件。
生成的文件与对应的 .cpp 题解放置在同一目录下。

用法:
    python luogu.py P1001              # 爬取单个题目
    python luogu.py P1001 P1002 P1003  # 爬取多个题目
    python luogu.py --all              # 爬取 source/website/www.luogu.com.cn/ 下所有已有题解对应的题目
    python luogu.py --dry-run P1001    # 预览生成内容而不写入文件

依赖:
    pip install requests
"""

import http.client
import json
import os
import re
import sys
import time
from datetime import datetime, timezone, timedelta
from pathlib import Path

# ─── 项目路径配置 ───────────────────────────────────────────
PROJECT_ROOT = Path(__file__).resolve().parent.parent.parent  # Competition/
LUOGU_SOURCE_DIR = PROJECT_ROOT / "source" / "website" / "www.luogu.com.cn"

# ─── 洛谷难度映射 ───────────────────────────────────────────
DIFFICULTY_MAP = {
    0: "暂无评定",
    1: "入门",
    2: "普及−",
    3: "普及/提高−",
    4: "普及+/提高",
    5: "提高+/省选−",
    6: "省选/NOI−",
    7: "NOI/NOI+/CTSC",
}

# ─── 洛谷标签映射（常见标签，ID 来源于洛谷 API）─────────────
TAG_MAP = {
    1: "入门与面试",
    2: "算法",
    3: "数据结构",
    4: "数学",
    5: "字符串",
    6: "图论",
    7: "动态规划",
    8: "计算几何",
    9: "博弈论",
    10: "搜索",
    11: "排序",
    12: "数论",
    13: "模拟",
    14: "枚举",
    15: "贪心",
    16: "分治",
    17: "倍增",
    18: "构造",
    19: "交互",
    20: "提交答案",
    21: "Special Judge",
    22: "O2优化",
    23: "高性能",
    24: "随机化",
    25: "前缀和",
    26: "差分",
    27: "位运算",
    28: "递归",
    29: "二分",
    30: "广度优先搜索BFS",
    31: "深度优先搜索DFS",
    32: "剪枝",
    33: "记忆化搜索",
    34: "启发式搜索",
    35: "迭代加深",
    36: "双向搜索",
    37: "Meet in the Middle",
    38: "A*",
    39: "IDA*",
    40: "堆",
    41: "栈",
    42: "队列",
    43: "链表",
    44: "单调栈",
    45: "单调队列",
    46: "并查集",
    47: "树状数组",
    48: "线段树",
    49: "平衡树",
    50: "分块",
    51: "莫队",
    52: "树链剖分",
    53: "可持久化",
    54: "左偏树",
    55: "替罪羊树",
    56: "Treap",
    57: "Splay",
    58: "树套树",
    59: "CDQ分治",
    60: "Link-Cut Tree",
    61: "点分治",
    62: "K-D Tree",
    63: "动态规划优化",
    64: "状压DP",
    65: "区间DP",
    66: "树形DP",
    67: "数位DP",
    68: "概率DP",
    69: "期望DP",
    70: "背包",
    71: "拓扑排序",
    72: "最短路",
    73: "最小生成树",
    74: "强连通分量",
    75: "双连通分量",
    76: "最近公共祖先LCA",
    77: "网络流",
    78: "二分图",
    79: "费用流",
    80: "上下界网络流",
    81: "最大流",
    82: "欧拉回路",
    83: "差分约束",
    84: "树的直径",
    85: "虚树",
    86: "基环树",
    87: "仙人掌",
    88: "快速傅里叶变换FFT",
    89: "快速数论变换NTT",
    90: "生成函数",
    91: "多项式",
    92: "线性代数",
    93: "矩阵",
    94: "高斯消元",
    95: "线性基",
    96: "概率论",
    97: "组合数学",
    98: "容斥原理",
    99: "鸽巢原理",
    100: "中国剩余定理CRT",
    101: "扩展欧几里得",
    102: "欧拉函数",
    103: "莫比乌斯反演",
    104: "Miller-Rabin",
    105: "Pollard-Rho",
    106: "BSGS",
    107: "原根",
    108: "二次剩余",
    109: "自动机",
    110: "AC自动机",
    111: "后缀自动机SAM",
    112: "后缀数组",
    113: "Manacher",
    114: "Trie树",
    115: "哈希",
    116: "KMP",
    117: "计算几何基础",
    118: "凸包",
    119: "旋转卡壳",
    120: "半平面交",
    121: "扫描线",
    122: "最小圆覆盖",
    123: "平面最近点对",
    124: "Voronoi图",
    125: "线性规划",
    126: "整数规划",
    127: "单纯形",
    128: "打表",
    129: "骗分",
    130: "提交答案",
    131: "提答",
    132: "交互题",
    133: "通信题",
}

# 扩展标签补充（以实际返回 ID 为准，持续补充）
# 洛谷的标签 ID 范围较大，这里预置常用标签
_TAG_EXTRA = {
    135: "快速幂",
    136: "逆元",
    137: "Lucas定理",
    138: "卡特兰数",
    139: "斯特林数",
    140: "矩阵快速幂",
    141: "矩阵加速",
    142: "向量",
    143: "卷积",
    144: "拉格朗日插值",
    145: "莫队",
    146: "树上莫队",
    147: "带修莫队",
    148: "回滚莫队",
}
TAG_MAP.update(_TAG_EXTRA)


def fetch_problem(pid: str) -> dict:
    """从洛谷 API 获取题目原始 JSON 数据。

    Args:
        pid: 题目 ID，如 "P1001"

    Returns:
        解析后的完整 JSON dict

    Raises:
        RuntimeError: HTTP 请求失败或响应状态非 200
        json.JSONDecodeError: 响应体不是合法 JSON
    """
    conn = http.client.HTTPSConnection("www.luogu.com.cn", timeout=30)
    headers = {
        "x-lentille-request": "content-only",
        "X-Requested-With": "XMLHttpRequest",
        "Referer": "https://www.luogu.com.cn/problem/list",
        "User-Agent": "Apifox/1.0.0 (https://apifox.com)",
        "Content-Type": "application/json",
        "Accept": "*/*",
        "Host": "www.luogu.com.cn",
        "Connection": "keep-alive",
    }

    conn.request("GET", f"/problem/{pid}", "", headers)
    res = conn.getresponse()
    body = res.read().decode("utf-8")

    if res.status != 200:
        raise RuntimeError(f"HTTP {res.status} for {pid}: {body[:200]}")

    return json.loads(body)


def parse_problem(raw: dict) -> dict:
    """从原始 JSON 中提取并整理题目结构化信息。

    Args:
        raw: fetch_problem 返回的原始 dict

    Returns:
        {
            "pid": str,           # 题目 ID
            "title": str,         # 题目标题
            "difficulty": str,    # 难度中文名
            "tags": list[str],    # 标签中文名列表
            "background": str,    # 题目背景 (Markdown)
            "description": str,   # 题目描述 (Markdown)
            "input_format": str,  # 输入格式 (Markdown)
            "output_format": str, # 输出格式 (Markdown)
            "samples": list[dict],# 样例列表
            "hint": str,          # 提示 (Markdown)
            "time_limit_ms": int, # 时间限制 (ms)，取第一个测试点
            "memory_limit_kb": int,# 内存限制 (KB)，取第一个测试点
            "total_submit": int,  # 总提交数
            "total_accepted": int,# 总通过数
            "source_url": str,    # 洛谷题目链接
        }
    """
    problem = raw["data"]["problem"]

    pid = problem["pid"]
    title = problem.get("name", pid)

    # 难度
    diff_code = problem.get("difficulty", 0)
    difficulty = DIFFICULTY_MAP.get(diff_code, f"未知({diff_code})")

    # 标签
    tag_ids = problem.get("tags", [])
    tags = [TAG_MAP.get(tid, f"Tag-{tid}") for tid in tag_ids]

    # 正文内容：优先取 content，其次 contenu（旧字段拼写保留）
    body = problem.get("content") or problem.get("contenu") or {}

    background = (body.get("background") or "").strip()
    description = (body.get("description") or "").strip()
    input_format = (body.get("formatI") or "").strip()
    output_format = (body.get("formatO") or "").strip()
    hint = (body.get("hint") or "").strip()

    # 样例
    raw_samples = problem.get("samples", [])
    samples = []
    for i, s in enumerate(raw_samples, 1):
        if isinstance(s, list) and len(s) >= 2:
            samples.append({"index": i, "input": s[0], "output": s[1]})

    # 时空限制（取所有测试点中最大的）
    limits = problem.get("limits", {})
    time_limits = limits.get("time", [1000])
    memory_limits = limits.get("memory", [262144])
    time_limit_ms = max(time_limits) if time_limits else 1000
    memory_limit_kb = max(memory_limits) if memory_limits else 262144

    # 统计数据
    total_submit = problem.get("totalSubmit", 0)
    total_accepted = problem.get("totalAccepted", 0)

    source_url = f"https://www.luogu.com.cn/problem/{pid}"

    return {
        "pid": pid,
        "title": title,
        "difficulty": difficulty,
        "tags": tags,
        "background": background,
        "description": description,
        "input_format": input_format,
        "output_format": output_format,
        "samples": samples,
        "hint": hint,
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


# 北京时区
_CST = timezone(timedelta(hours=8))


def _crawl_time_str() -> str:
    """返回当前北京时间字符串，用于写入爬取时间字段。"""
    return datetime.now(_CST).strftime("%Y-%m-%d %H:%M:%S")


def generate_problem_md(info: dict) -> str:
    """根据题目结构化信息生成 .problem.md 的 Markdown 内容。

    Args:
        info: parse_problem 返回的 dict

    Returns:
        完整的 .problem.md 内容字符串
    """
    tags_str = " / ".join(info["tags"]) if info["tags"] else "无"
    memory_str = format_memory(info["memory_limit_kb"])

    lines = [
        f"# {info['pid']} {info['title']}",
        "",
        "| 属性 | 值 |",
        "|------|-----|",
        f"| 题目编号 | {info['pid']} |",
        f"| 题目来源 | [洛谷]({info['source_url']}) |",
        f"| 难度 | {info['difficulty']} |",
        f"| 标签 | {tags_str} |",
        f"| 时间限制 | {info['time_limit_ms']} ms |",
        f"| 内存限制 | {memory_str} |",
        f"| 总提交数 | {info['total_submit']} |",
        f"| 总通过数 | {info['total_accepted']} |",
        f"| 爬取时间 | {_crawl_time_str()} |",
        "",
    ]

    # 题目背景
    if info["background"]:
        lines.append("## 题目背景")
        lines.append("")
        lines.append(info["background"])
        lines.append("")

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
            lines.append(s["input"].rstrip())
            lines.append("```")
            lines.append("")
            lines.append("### 样例输出")
            lines.append("")
            lines.append("```")
            lines.append(s["output"].rstrip())
            lines.append("```")
            lines.append("")

    # 提示
    if info["hint"]:
        lines.append("## 提示")
        lines.append("")
        lines.append(info["hint"])
        lines.append("")

    return "\n".join(lines)


def get_existing_luogu_problems() -> list[str]:
    """扫描 source/website/www.luogu.com.cn/ 目录，提取所有已有 .cpp 解答的题目 ID。

    Returns:
        题目 ID 列表（如 ["P1001", "P1002"]），已去重排序
    """
    if not LUOGU_SOURCE_DIR.exists():
        print(f"[WARN] 目录不存在: {LUOGU_SOURCE_DIR}")
        return []

    pids = set()
    for f in LUOGU_SOURCE_DIR.iterdir():
        if not f.is_file():
            continue
        # 匹配文件名中的题目 ID，如 P1001.cpp, P1001.helper.cpp, P1001-2.cpp
        m = re.match(r"^(P\d+)", f.name)
        if m:
            pids.add(m.group(1))

    return sorted(pids)


def run_single(pid: str, dry_run: bool = False) -> bool:
    """爬取单个题目并生成 .problem.md。

    Args:
        pid: 题目 ID
        dry_run: 为 True 时只打印不写文件

    Returns:
        是否成功
    """
    print(f"[INFO] 正在获取 {pid} ...", end=" ", flush=True)

    try:
        raw = fetch_problem(pid)
        info = parse_problem(raw)
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
    out_path = LUOGU_SOURCE_DIR / f"{pid}.problem.md"
    out_path.write_text(md_content, encoding="utf-8")
    print(f"[OK] 已写入: {out_path}")
    return True


def main():
    import argparse

    parser = argparse.ArgumentParser(
        description="洛谷题目爬虫 — 从洛谷 API 获取题目数据，生成 .problem.md",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
示例:
  python luogu.py P1001              # 爬取单个题目
  python luogu.py P1001 P1002 P1003  # 批量爬取
  python luogu.py --all              # 爬取所有已有题解对应的题目
  python luogu.py --dry-run P1001    # 预览不写入
        """,
    )
    parser.add_argument("pids", nargs="*", help="题目 ID 列表（如 P1001 P1002）")
    parser.add_argument("--all", action="store_true", help="爬取所有已有 .cpp 解答的题目")
    parser.add_argument("--dry-run", action="store_true", help="仅预览，不写入文件")

    args = parser.parse_args()

    # 确定要爬取的题目列表
    if args.all:
        pids = get_existing_luogu_problems()
        if not pids:
            print("[ERROR] 未找到任何已有 .cpp 解答的洛谷题目")
            sys.exit(1)
        print(f"[INFO] 发现 {len(pids)} 个已有题解的洛谷题目")
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
            time.sleep(0.5)  # 请求间隔，避免被限流
        if run_single(pid, dry_run=args.dry_run):
            success += 1
        else:
            fail += 1

    print(f"\n[DONE] 成功 {success}, 失败 {fail}, 总计 {len(pids)}")


if __name__ == "__main__":
    main()
