#!/usr/bin/env python3
"""
题解网站 — 索引生成器
======================
扫描 source/ 目录，解析题目元数据，生成 website/index.json。

用法:
    source .venv/bin/activate
    python generate_index.py              # 输出到 ../index.json
    python generate_index.py --help       # 查看选项
"""

import json
import re
import sys
from datetime import datetime, timezone, timedelta
from pathlib import Path
from typing import Any

# ─── 路径配置 ───────────────────────────────────────────────
SCRIPT_DIR = Path(__file__).resolve().parent          # website/scripts/
WEBSITE_DIR = SCRIPT_DIR.parent                       # website/
PROJECT_ROOT = SCRIPT_DIR.parent.parent               # Competition/
SOURCE_DIR = PROJECT_ROOT / "source"

INDEX_OUTPUT = WEBSITE_DIR / "index.json"

# ─── OJ 平台名称映射 ────────────────────────────────────────
OJ_NAME_MAP: dict[str, str] = {
    "www.luogu.com.cn":   "洛谷",
    "ybt.ssoier.cn":      "一本通",
    "cjsoj.cn":           "常菁数 OJ",
    "oj.crequency.cn":    "云矩创频 OJ",
    "xiaopangoj.com":     "小胖 OJ",
    "www.51nod.com":      "51Nod",
}

# ─── 竞赛名称映射 ───────────────────────────────────────────
COMPETITION_NAME_MAP: dict[str, str] = {
    "coci":  "克罗地亚公开信息学竞赛",
    "csp":   "CSP 认证",
    "noi":   "全国青少年信息学奥林匹克",
    "noip":  "全国青少年信息学奥林匹克联赛",
    "usaco": "美国计算机奥林匹克",
}

# ─── 时区 ──────────────────────────────────────────────────
CST = timezone(timedelta(hours=8))


def parse_problem_md(filepath: Path) -> dict[str, Any] | None:
    """解析 .problem.md 文件，提取元数据。

    解析开头表格（| 属性 | 值 |）中的字段。
    """
    if not filepath.exists():
        return None

    text = filepath.read_text(encoding="utf-8")

    # 提取标题：第一行 # PID Title
    title_match = re.match(r"^#\s+\S+\s+(.+)$", text, re.MULTILINE)
    title = title_match.group(1).strip() if title_match else ""

    # 提取表格中的键值对
    meta: dict[str, str] = {}
    in_table = False
    for line in text.split("\n"):
        line = line.strip()
        # 表头行
        if line.startswith("| 属性 ") or line.startswith("|------"):
            in_table = True
            continue
        if in_table:
            if not line.startswith("|"):
                break  # 表格结束
            m = re.match(r"\|\s*(.+?)\s*\|\s*(.+?)\s*\|", line)
            if m:
                key = m.group(1).strip()
                val = m.group(2).strip()
                meta[key] = val

    # 提取标签（可能以 " / " 分隔多个标签）
    tags_str = meta.get("标签", "")
    tags = [t.strip() for t in tags_str.split("/") if t.strip()] if tags_str else []

    # 提取数值
    def _int(val: str) -> int:
        try:
            return int(val)
        except (ValueError, TypeError):
            return 0

    return {
        "title": title,
        "difficulty": meta.get("难度", ""),
        "tags": tags,
        "sourceUrl": _extract_link(meta.get("题目来源", "")),
        "timeLimitMs": _int(meta.get("时间限制", "").replace(" ms", "")),
        "memoryLimitKb": _parse_memory_kb(meta.get("内存限制", "")),
        "totalSubmit": _int(meta.get("总提交数", "")),
        "totalAccepted": _int(meta.get("总通过数", "")),
        "crawlTime": meta.get("爬取时间", ""),
    }


def _extract_link(md_link: str) -> str:
    """从 Markdown 链接 [text](url) 中提取 url。"""
    m = re.search(r"\]\((.+?)\)", md_link)
    return m.group(1) if m else ""


def _parse_memory_kb(s: str) -> int:
    """将内存限制字符串转换为 KB 整数。"""
    s = s.strip().upper()
    try:
        if "GB" in s:
            return int(float(s.replace("GB", "")) * 1048576)
        if "MB" in s:
            return int(float(s.replace("MB", "")) * 1024)
        if "KB" in s:
            return int(float(s.replace("KB", "")))
        return int(s) if s else 0
    except (ValueError, TypeError):
        return 0


def scan_oj_problems(oj_dir: Path, oj_key: str) -> list[dict[str, Any]]:
    """扫描单个 OJ 目录下所有题目的三件套文件。

    Args:
        oj_dir: 如 source/website/www.luogu.com.cn/
        oj_key: 如 "www.luogu.com.cn"

    Returns:
        题目信息列表
    """
    problems: dict[str, dict[str, Any]] = {}

    # 收集所有文件，按题目 ID 分组
    for filepath in oj_dir.iterdir():
        if not filepath.is_file():
            continue

        name = filepath.name
        # 提取题目 ID：P1001, 1000, C0001 等
        m = re.match(r"^([A-Z]?\d+)", name)
        if not m:
            # 处理中文文件名（如 xiaopangoj 的 "括号匹配.cpp"）
            stem = filepath.stem
            # 去掉已知后缀变体
            base = re.sub(r"-\d+$|\.helper$", "", stem)
            pid = base if base else stem
        else:
            pid = m.group(1)

        if pid not in problems:
            problems[pid] = {"id": pid, "files": {}}

        suffix = name[len(pid):]  # ".cpp", ".problem.md", ".explain.md", "-1.cpp" 等

        if suffix.endswith(".problem.md"):
            problems[pid]["files"]["problem"] = name
        elif suffix.endswith(".explain.md"):
            problems[pid]["files"]["explain"] = name
        elif suffix.endswith(".cpp") or suffix.endswith(".c"):
            # 区分主文件和变体文件
            if suffix == ".cpp" or suffix == ".c":
                problems[pid]["files"]["code"] = name
            else:
                # 变体文件，如 P1662.helper.cpp, 1351-1.cpp
                variants = problems[pid].setdefault("variants", [])
                variants.append(name)

    # 为每个题目补充元数据
    result: list[dict[str, Any]] = []
    for pid, entry in sorted(problems.items()):
        # 尝试解析 .problem.md
        prob_file = entry.get("files", {}).get("problem")
        meta = None
        if prob_file:
            meta = parse_problem_md(oj_dir / prob_file)

        item: dict[str, Any] = {
            "id": pid,
            "oj": oj_key,
            "ojName": OJ_NAME_MAP.get(oj_key, oj_key),
            "title": meta.get("title", pid) if meta else pid,
            "difficulty": meta.get("difficulty", "") if meta else "",
            "tags": meta.get("tags", []) if meta else [],
            "sourceUrl": meta.get("sourceUrl", "") if meta else "",
            "timeLimitMs": meta.get("timeLimitMs", 0) if meta else 0,
            "memoryLimitKb": meta.get("memoryLimitKb", 0) if meta else 0,
            "totalSubmit": meta.get("totalSubmit", 0) if meta else 0,
            "totalAccepted": meta.get("totalAccepted", 0) if meta else 0,
            "crawlTime": meta.get("crawlTime", "") if meta else "",
            "files": entry.get("files", {}),
        }

        if "variants" in entry:
            item["variants"] = entry["variants"]

        result.append(item)

    return result


def scan_competitions(base_dir: Path, rel_path: Path = Path()) -> list[dict[str, Any]]:
    """递归扫描 competitions/ 目录。

    目录结构: competitions/{comp}/{year}/{stage}/{problem}.cpp
    例如: competitions/noip/j/2019/公交换乘.cpp
    """
    results: list[dict[str, Any]] = []
    current = base_dir / rel_path

    if not current.exists() or not current.is_dir():
        return results

    # 判断当前层级：如果目录中直接有 .cpp 文件，这就是叶子层
    cpp_files = sorted(current.glob("*.cpp")) + sorted(current.glob("*.c"))
    if cpp_files:
        # 从路径中提取竞赛信息
        parts = rel_path.parts  # e.g. ("noip", "j", "2019")
        comp_key = parts[0] if len(parts) > 0 else ""
        comp_name = COMPETITION_NAME_MAP.get(comp_key, comp_key)
        year = ""
        stage = ""
        for p in parts[1:]:
            if re.match(r"^\d{4}", p):
                year = p
            else:
                stage = p if stage else stage + "/" + p if stage else p

        for f in cpp_files:
            pid = f.stem
            # 去掉可能的变体后缀
            base_id = re.sub(r"-\d+$", "", pid)
            is_variant = (base_id != pid)

            title = pid  # 用文件名作为标题
            # 尝试美化中文文件名
            if re.search(r'[一-鿿]', title):
                pass  # 保留中文标题

            if not is_variant:
                results.append({
                    "id": pid,
                    "type": "competition",
                    "competition": comp_key,
                    "competitionName": comp_name,
                    "year": year,
                    "stage": stage,
                    "title": title,
                    "difficulty": "",
                    "tags": [],
                    "sourceUrl": "",
                    "files": {
                        "code": f.name,
                    },
                })

        return results

    # 递归子目录
    for sub in sorted(current.iterdir()):
        if sub.is_dir() and not sub.name.startswith("."):
            sub_rel = rel_path / sub.name if str(rel_path) != "." else Path(sub.name)
            results.extend(scan_competitions(base_dir, sub_rel))

    return results


def scan_districts(base_dir: Path) -> list[dict[str, Any]]:
    """扫描 districts/ 目录。"""
    results: list[dict[str, Any]] = []

    if not base_dir.exists():
        return results

    for cpp_file in sorted(base_dir.rglob("*.cpp")):
        # 跳过非代码文件
        rel = cpp_file.relative_to(base_dir)
        parts = rel.parts  # e.g. ("cq", "cqyc", "2021", "12-25", "base.cpp")

        district = parts[0] if len(parts) > 0 else ""
        school = parts[1] if len(parts) > 1 else ""
        year = ""
        date = ""
        for p in parts[2:]:
            if re.match(r"^\d{4}", p):
                year = p
            elif re.match(r"^\d{2}-\d{2}", p):
                date = p

        title = cpp_file.stem
        results.append({
            "id": title,
            "type": "district",
            "district": district,
            "school": school,
            "year": year,
            "date": date,
            "title": title,
            "difficulty": "",
            "tags": [],
            "sourceUrl": "",
            "files": {
                "code": str(rel),
            },
        })

    return results


def build_tag_index(problems: list[dict[str, Any]]) -> list[dict[str, Any]]:
    """统计所有标签的出现次数和对应题目数。"""
    tag_count: dict[str, int] = {}
    tag_problems: dict[str, list[str]] = {}

    for p in problems:
        for t in p.get("tags", []):
            tag_count[t] = tag_count.get(t, 0) + 1
            tag_problems.setdefault(t, []).append(p["id"])

    return [
        {
            "name": tag,
            "count": tag_count[tag],
        }
        for tag in sorted(tag_count.keys(), key=lambda t: -tag_count[t])
    ]


def main():
    import argparse

    parser = argparse.ArgumentParser(description="生成题解网站索引 JSON")
    parser.add_argument(
        "-o", "--output",
        default=str(INDEX_OUTPUT),
        help=f"输出文件路径（默认: {INDEX_OUTPUT}）",
    )
    parser.add_argument("--pretty", action="store_true", help="格式化 JSON 输出")
    args = parser.parse_args()

    all_problems: list[dict[str, Any]] = []
    oj_summary: list[dict[str, Any]] = []

    # ── 1. 扫描 website/ OJ 目录 ──
    website_dir = SOURCE_DIR / "website"
    if website_dir.exists():
        for oj_dir in sorted(website_dir.iterdir()):
            if not oj_dir.is_dir():
                continue
            oj_key = oj_dir.name
            if OJ_NAME_MAP.get(oj_key) is None:
                continue  # 跳过未映射的目录（如 . 开头的隐藏目录）

            probs = scan_oj_problems(oj_dir, oj_key)
            all_problems.extend(probs)
            oj_summary.append({
                "key": oj_key,
                "name": OJ_NAME_MAP[oj_key],
                "count": len(probs),
            })

    # ── 2. 扫描 competitions/ ──
    comp_dir = SOURCE_DIR / "competitions"
    if comp_dir.exists():
        comp_problems = scan_competitions(comp_dir)
        all_problems.extend(comp_problems)
        # 统计各竞赛数量
        comp_count: dict[str, int] = {}
        for p in comp_problems:
            k = p.get("competition", "other")
            comp_count[k] = comp_count.get(k, 0) + 1
        for key, count in sorted(comp_count.items()):
            oj_summary.append({
                "key": f"competitions/{key}",
                "name": COMPETITION_NAME_MAP.get(key, key),
                "count": count,
                "type": "competition",
            })

    # ── 3. 扫描 districts/ ──
    dist_dir = SOURCE_DIR / "districts"
    if dist_dir.exists():
        dist_problems = scan_districts(dist_dir)
        all_problems.extend(dist_problems)
        if dist_problems:
            oj_summary.append({
                "key": "districts",
                "name": "地区训练",
                "count": len(dist_problems),
                "type": "district",
            })

    # ── 4. 构建标签索引 ──
    tags_index = build_tag_index(all_problems)

    # ── 5. 构建难度分布 ──
    difficulty_dist: dict[str, int] = {}
    for p in all_problems:
        d = p.get("difficulty", "") or "暂无评定"
        difficulty_dist[d] = difficulty_dist.get(d, 0) + 1

    # ── 6. 组装输出 ──
    index = {
        "generatedAt": datetime.now(CST).strftime("%Y-%m-%d %H:%M:%S"),
        "summary": {
            "totalProblems": len(all_problems),
            "totalOJs": len([o for o in oj_summary if o.get("type") != "district" and o.get("type") != "competition"]),
            "withMetadata": sum(1 for p in all_problems if p.get("difficulty") or p.get("tags")),
            "withoutMetadata": sum(1 for p in all_problems if not p.get("difficulty") and not p.get("tags")),
        },
        "ojs": oj_summary,
        "tags": tags_index,
        "difficulties": [
            {"name": k, "count": v}
            for k, v in sorted(difficulty_dist.items())
        ],
        "problems": all_problems,
    }

    output_path = Path(args.output)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    with open(output_path, "w", encoding="utf-8") as f:
        if args.pretty:
            json.dump(index, f, ensure_ascii=False, indent=2)
        else:
            json.dump(index, f, ensure_ascii=False, separators=(",", ":"))

    print(f"[OK] 索引已生成: {output_path}")
    print(f"     总题目数: {index['summary']['totalProblems']}")
    print(f"     OJ 题目: {sum(o['count'] for o in oj_summary if o.get('type') != 'competition' and o.get('type') != 'district')}")
    print(f"     竞赛题目: {sum(o['count'] for o in oj_summary if o.get('type') == 'competition')}")
    print(f"     地区训练: {sum(o['count'] for o in oj_summary if o.get('type') == 'district')}")
    print(f"     含完整元数据: {index['summary']['withMetadata']}")
    print(f"     仅代码: {index['summary']['withoutMetadata']}")


if __name__ == "__main__":
    main()
