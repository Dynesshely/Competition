<p align="center">
<pre align="center">
                                      ____________________
___________________ __________________  /___(_)_  /___(_)____________
_  ___/  __ \_  __ `__ \__  __ \  _ \  __/_  /_  __/_  /_  __ \_  __ \
/ /__ / /_/ /  / / / / /_  /_/ /  __/ /_ _  / / /_ _  / / /_/ /  / / /
\___/ \____//_/ /_/ /_/_  .___/\___/\__/ /_/  \__/ /_/  \____//_/ /_/
                       /_/
</pre>
</p>

# Competition

个人算法竞赛（OI）代码仓库，记录信息学竞赛中遇到的题目及对应题解。

[![License: CC0-1.0](https://img.shields.io/badge/License-CC0_1.0-lightgrey.svg)](http://creativecommons.org/publicdomain/zero/1.0/)

---

## 目录结构

```
Competition/
├── LICENSE                    # CC0 1.0（仅适用于 source/ templates/ documents/）
├── LICENSE.md                 # 许可证详细说明
├── README.md                  # 本文件
├── .gitignore
├── .clang-format              # C++ 代码格式化配置
│
├── source/                    # 题解代码（按来源分类）
│   ├── competitions/          # 正式竞赛
│   │   ├── coci/2006/         # 克罗地亚公开信息学竞赛
│   │   ├── csp/               # 中国 CSP 认证
│   │   ├── noi/2003/          # 全国青少年信息学奥林匹克
│   │   ├── noip/              # 全国青少年信息学奥林匹克联赛
│   │   └── usaco/             # 美国计算机奥林匹克
│   ├── districts/             # 地区训练
│   │   └── cq/cqyc/           # 重庆育才中学
│   └── website/               # OJ 平台题目
│       ├── www.luogu.com.cn/  # 洛谷
│       ├── ybt.ssoier.cn/     # 一本通
│       ├── oj.crequency.cn/   # 云矩创频 OJ
│       ├── cjsoj.cn/          # 常菁数 OJ
│       ├── xiaopangoj.com/    # 小胖 OJ
│       └── www.51nod.com/     # 51Nod
│
├── templates/                 # 算法模板（线段树、KMP、高精度等）
│
├── documents/                 # 学习文档
│   ├── oier-notices.md        # OIer 考前注意事项（101+ 条）
│   ├── fragments.md           # 算法片段备忘
│   └── OI.xmind               # OI 知识体系思维导图
│
├── website/                   # 题解网站项目（开发中）
│   └── scripts/               # 爬虫脚本
│       ├── luogu.py           # 洛谷题目爬虫
│       ├── ybt.py             # 一本通题目爬虫
│       └── README.md          # 脚本使用说明
│
└── utils/                     # 工具脚本
    └── compile-all.sh         # 批量编译脚本
```

## 文件命名规范（OJ 题目）

每道 OJ 题目由三个文件组成，存放在对应平台的目录下：

| 后缀          | 用途                      | 示例               |
| ------------- | ------------------------- | ------------------ |
| `.cpp`        | AC 题解代码               | `P1001.cpp`        |
| `.exe`        | 编译产物（Windows）       | `P1001.exe`        |
| `.out`        | 编译产物（Linux / macOS） | `P1001.out`        |
| `.problem.md` | 题目描述（爬虫生成）      | `P1001.problem.md` |
| `.explain.md` | 题解说明（手动编写）      | `P1001.explain.md` |

## 覆盖平台

| 平台        | 目录                | 题目数 |
| ----------- | ------------------- | ------ |
| 洛谷        | `www.luogu.com.cn/` | 45     |
| 一本通      | `ybt.ssoier.cn/`    | 149    |
| 云矩创频 OJ | `oj.crequency.cn/`  | —      |
| 常菁数 OJ   | `cjsoj.cn/`         | —      |
| 小胖 OJ     | `xiaopangoj.com/`   | —      |
| 51Nod       | `www.51nod.com/`    | —      |

## 算法覆盖

数据结构（线段树、树状数组、并查集）、动态规划（背包、区间、状压、数位、树形 DP）、
图论（最短路、网络流、二分图、拓扑排序）、字符串（KMP、哈希）、
数学（数论、组合、容斥、博弈）、搜索（DFS/BFS、回溯）、贪心、分治、计算几何。

## 编译

```bash
# 单文件
g++ -std=c++17 -O2 source/website/www.luogu.com.cn/P1001.cpp

# 批量编译
bash utils/compile-all.sh              # 顺序编译全部
bash utils/compile-all.sh -j4          # 4 线程并行
bash utils/compile-all.sh --dry-run    # 仅列出文件
```

## 许可证

- **`source/`、`templates/`、`documents/`**：CC0 1.0 Universal（公共领域），详见 [LICENSE](LICENSE) 和 [LICENSE.md](LICENSE.md)
- **`website/`**：保留所有权利，将在后续单独授权
- **`.problem.md` 题目描述**：版权归各 OJ 平台及原题作者所有
