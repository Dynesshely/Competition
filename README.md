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

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![License: AGPL-3.0](https://img.shields.io/badge/License-AGPL--3.0-red.svg)](LICENSE.AGPL)

---

## 目录结构

```
Competition/
├── LICENSE                                     # MIT 许可证（适用于 source/ templates/ documents/）
├── LICENSE.AGPL                                # AGPL-3.0 许可证（适用于 website/）
├── LICENSE.md                                  # 许可证详细说明
├── README.md                                   # 本文件
├── .gitignore
├── .clang-format                               # C++ 代码格式化配置
│
├── source/                                     # 题解代码（按来源分类）
│   ├── competitions/                           # 正式竞赛
│   │   ├── coci/2006/                          # 克罗地亚公开信息学竞赛
│   │   ├── csp/                                # 中国 CSP 认证
│   │   ├── noi/2003/                           # 全国青少年信息学奥林匹克
│   │   ├── noip/                               # 全国青少年信息学奥林匹克联赛
│   │   └── usaco/                              # 美国计算机奥林匹克
│   ├── districts/                              # 地区训练
│   │   └── cq/cqyc/                            # 重庆育才中学
│   └── website/                                # OJ 平台题目
│       ├── www.luogu.com.cn/                   # 洛谷
│       │   └── utils/                          # 洛谷辅助工具
│       │       ├── script-cat/                 # 用户脚本「洛谷助手」
│       │       └── chromium-ext-auto-submit/   # 浏览器扩展「洛谷自动提交」
│       ├── ybt.ssoier.cn/                      # 一本通
│       ├── oj.crequency.cn/                    # 云矩创频 OJ
│       ├── cjsoj.cn/                           # 常菁数 OJ
│       ├── xiaopangoj.com/                     # 小胖 OJ
│       └── www.51nod.com/                      # 51Nod
│
├── templates/                                  # 算法模板（BIT、线段树、KMP、高精度等）
│
├── documents/                                  # 学习文档
│   ├── oier-notices.md                         # OIer 考前注意事项（101+ 条）
│   ├── fragments.md                            # 算法片段备忘
│   └── OI.xmind                                # OI 知识体系思维导图
│
├── website/                                    # 题解网站项目（开发中）
│   └── scripts/                                # 爬虫脚本
│       ├── luogu.py                            # 洛谷题目爬虫
│       ├── ybt.py                              # 一本通题目爬虫
│       └── README.md                           # 脚本使用说明
│
└── utils/                                      # 工具脚本
    ├── compile-all.sh                          # 批量编译脚本
    └── run.sh                                  # 编译运行脚本（含 --install 安装 runcpp 别名）
```

## 文件命名规范（OJ 题目）

每道 OJ 题目由三个文件组成，存放在对应平台的目录下：

| 后缀              | 用途                      | 示例               |
| ----------------- | ------------------------- | ------------------ |
| `.cpp`            | AC 题解代码               | `P1001.cpp`        |
| `.exe`            | 编译产物（Windows）       | `P1001.exe`        |
| `.out`            | 编译产物（Linux / macOS） | `P1001.out`        |
| `.problem.md`     | 题目描述（爬虫生成）      | `P1001.problem.md` |
| `.explain.md`     | 题解说明（手动编写）      | `P1001.explain.md` |
| `<pid>_<did>.in`  | 测试输入数据              | `P1098_6.in`       |
| `<pid>_<did>.ans` | 测试输出数据              | `P1098_6.ans`      |

## 覆盖平台

| 平台        | 目录                | 题目数 |
| ----------- | ------------------- | ------ |
| 洛谷        | `www.luogu.com.cn/` | 596    |
| 一本通      | `ybt.ssoier.cn/`    | 153    |
| 育才中学    | `cq/cqyc/`          | 77     |
| USACO       | `usaco/`            | 28     |
| COCI        | `coci/2006/`        | 7      |
| NOIP        | `noip/`             | 24     |
| CSP         | `csp/`              | 3      |
| 常菁数 OJ   | `cjsoj.cn/`         | 31     |
| 云矩创频 OJ | `oj.crequency.cn/`  | 19     |
| 小胖 OJ     | `xiaopangoj.com/`   | 16     |
| 51Nod OJ    | `www.51nod.com/`    | 15     |

## 算法覆盖

数据结构（线段树、树状数组、并查集）、动态规划（背包、区间、状压、数位、树形 DP）、
图论（最短路、网络流、二分图、拓扑排序）、字符串（KMP、哈希）、
数学（数论、组合、容斥、博弈）、搜索（DFS/BFS、回溯）、贪心、分治、计算几何。

## 编译

```bash
# 单文件
g++ -std=c++17 -O2 source/website/www.luogu.com.cn/P1001.cpp

# 编译并运行（自动生成 .out 产物并执行）
bash utils/run.sh source/website/www.luogu.com.cn/P1001.cpp

# 安装 runcpp 别名（写入 ~/.bashrc / ~/.zshrc 等）
bash utils/run.sh --install
# 安装后可直接使用: runcpp source/website/www.luogu.com.cn/P1001.cpp

# 批量编译
bash utils/compile-all.sh              # 顺序编译全部
bash utils/compile-all.sh -j4          # 4 线程并行
bash utils/compile-all.sh --dry-run    # 仅列出文件
```

## 用户脚本

[洛谷助手](https://greasyfork.org/zh-CN/scripts/581027-%E6%B4%9B%E8%B0%B7%E5%8A%A9%E6%89%8B) 是一个运行在 [ScriptCat](https://docs.scriptcat.org/) 上的用户脚本，用于增强洛谷题目列表页的交互体验。

**功能：** 在洛谷题目列表页（`/problem/list`）页面右下角添加悬浮按钮，点击后弹出面板展示：

- **已通过** 题目编号列表 + 一键复制
- **未通过** 题目编号列表 + 一键复制
- **未做** 题目编号列表 + 一键复制

**使用方式：**

1. 安装用户脚本管理器（[ScriptCat](https://docs.scriptcat.org/) 或 Tampermonkey）
2. 访问 [Greasy Fork 页面](https://greasyfork.org/zh-CN/scripts/581027-%E6%B4%9B%E8%B0%B7%E5%8A%A9%E6%89%8B) 安装脚本
3. 打开任意洛谷题目列表页，即可看到右下角的悬浮按钮

**开发：**

```bash
cd source/website/www.luogu.com.cn/utils/script-cat
npm install
npm run dev      # 开发模式（热更新）
npm run build    # 构建产物至 dist/
```

## 浏览器扩展

[洛谷自动提交](source/website/www.luogu.com.cn/utils/chromium-ext-auto-submit/) 是一个 Chrome MV3 扩展项目，通过终端 → 本地服务 → 浏览器三组件协作，实现代码批量在线评测的自动化。

**架构：**

```
CLI (终端) --HTTP--> Daemon (后台服务) --WebSocket--> Extension (浏览器)
```

| 组件           | 位置          | 端口                 | 职责                                   |
| -------------- | ------------- | -------------------- | -------------------------------------- |
| `luogu-cli`    | 终端          | —                    | 扫描代码文件、提交任务、展示结果       |
| `luogu-daemon` | 后台守护进程  | HTTP :9527, WS :9528 | 任务队列调度、SQLite 持久化、桥接扩展  |
| Extension      | Chrome 浏览器 | —                    | 页面自动化（填代码、点提交）、结果采集 |

**使用实例：**

```bash
# 启动后台服务
cd source/website/www.luogu.com.cn/utils/chromium-ext-auto-submit
pnpm --filter @luogu-auto/daemon dev

# 安装 CLI 别名（一次性）
./utils/luogu.sh --install
# or execute: eval "alias luogu='/home/dynesshely/projects/dynesshely/Competition/utils/luogu.sh'"

# 单题提交
luogu submit source/website/www.luogu.com.cn/P/1000-1049/P1000.cpp

# 批量提交（含 Markdown 结果汇总）
luogu batch source/website/www.luogu.com.cn/ --export markdown

# 批量提交指定范围
luogu batch source/website/www.luogu.com.cn/P/1400-1499/ --include 'P14(0[2-9]|1[0-9])'
```

**开发：**

```bash
cd source/website/www.luogu.com.cn/utils/chromium-ext-auto-submit
pnpm install
pnpm build      # 构建全部 4 个包
```

## 社区

[![Contributors](https://contrib.rocks/image?repo=Dynesshely/Competition)](https://github.com/Dynesshely/Competition/graphs/contributors)

<a href="https://www.star-history.com/?repos=Dynesshely%2FCompetition&type=date&legend=top-left">
 <picture>
   <source media="(prefers-color-scheme: dark)" srcset="https://api.star-history.com/image?repos=Dynesshely%2FCompetition&type=date&theme=dark&legend=top-left" />
   <source media="(prefers-color-scheme: light)" srcset="https://api.star-history.com/image?repos=Dynesshely%2FCompetition&type=date&legend=top-left" />
   <img alt="Star History Chart" src="https://api.star-history.com/image?repos=Dynesshely%2FCompetition&type=date&legend=top-left" />
 </picture>
</a>

## 许可证

- **`source/`、`templates/`、`documents/`**：[MIT](LICENSE) — 自由使用、修改、分发，需保留版权声明
- **`website/`、`utils/`**：[AGPL-3.0](LICENSE.AGPL) — 允许使用和修改，但衍生作品及网络服务必须开源
- **`.problem.md` 题目描述**：版权归各 OJ 平台及原题作者所有

> 详细的适用范围与例外说明请参阅 **[LICENSE.md](LICENSE.md)**。
