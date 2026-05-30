# Scripts — 题解网站爬虫工具

本目录包含用于从各 OJ 平台抓取题目数据的爬虫脚本。

---

## 文件命名规范

每道题目由 **三个文件** 组成，放在对应 OJ 平台的目录下：

| 后缀          | 用途     | 来源             | 示例                                               |
| ------------- | -------- | ---------------- | -------------------------------------------------- |
| `.cpp`        | 题解代码 | 手写（AC 代码）  | `source/website/www.luogu.com.cn/P1001.cpp`        |
| `.problem.md` | 题目描述 | 爬虫生成         | `source/website/www.luogu.com.cn/P1001.problem.md` |
| `.explain.md` | 题解说明 | 手写（解题思路） | `source/website/www.luogu.com.cn/P1001.explain.md` |

**示例**（洛谷 P1001）：

```
source/website/www.luogu.com.cn/
├── P1001.cpp          # AC 代码
├── P1001.problem.md   # 题目描述（爬虫自动生成）
└── P1001.explain.md   # 题解说明（手动编写）
```

---

## 虚拟环境

项目使用 Python 虚拟环境（`.venv`），配置了 `include-system-site-packages = true`。

### 激活

```bash
source .venv/bin/activate
```

### 依赖

| 包               | 用途      | 来源                |
| ---------------- | --------- | ------------------- |
| `beautifulsoup4` | HTML 解析 | venv（pip install） |
| `requests`       | HTTP 请求 | venv（pip install） |
| `soupsieve`      | bs4 依赖  | venv（自动安装）    |
| `certifi`        | SSL 证书  | venv（自动安装）    |
| `charset-normalizer` | 编码检测 | venv（自动安装） |
| `idna`           | 国际化域名 | venv（自动安装）    |
| `urllib3`        | HTTP 底层 | venv（自动安装）    |

### 安装新依赖

```bash
source .venv/bin/activate
pip install <package>
```

> **注意**：如果默认 PyPI 下载超时，可使用清华镜像：
> ```bash
> pip install -i https://pypi.tuna.tsinghua.edu.cn/simple <package>
> ```

---

## 爬取目标

### 洛谷 (Luogu)

| 项目         | 值                                             |
| ------------ | ---------------------------------------------- |
| 题目 URL     | `https://www.luogu.com.cn/problem/{PID}`       |
| API 方式     | HTTP Header `x-lentille-request: content-only` |
| 数据格式     | JSON（嵌入在 HTML `<script>` 标签中）          |
| 题目 ID 格式 | `P` + 数字（如 `P1001`）                       |
| 本地目录     | `source/website/www.luogu.com.cn/`             |

### 一本通 (YBT)

| 项目         | 值                                                 |
| ------------ | -------------------------------------------------- |
| 题目 URL     | `https://ybt.ssoier.cn/problem_show.php?pid={PID}` |
| API 方式     | HTML 解析（`pshow()` 脚本 + `<pre>` 标签）         |
| 数据格式     | HTML 页面（GB2312/UTF-8 编码）                     |
| 题目 ID 格式 | 纯数字（如 `1000`）                                |
| 本地目录     | `source/website/ybt.ssoier.cn/`                    |

---

## 脚本用法

### luogu.py

```bash
# 激活 venv
source .venv/bin/activate

# 预览（不写文件）
python luogu.py --dry-run P1001

# 爬取单个题目
python luogu.py P1001

# 批量爬取
python luogu.py P1001 P1002 P1003

# 爬取所有已有 .cpp 解答的题目
python luogu.py --all
```

### ybt.py

```bash
# 激活 venv
source .venv/bin/activate

# 预览（不写文件）
python ybt.py --dry-run 1000

# 爬取单个题目
python ybt.py 1000

# 批量爬取
python ybt.py 1000 1001 1002

# 爬取所有已有 .cpp 解答的题目（3700+ 题，耗时约 1 小时）
python ybt.py --all
```

### 注意事项

- 请求间隔：Luogu 0.5s，YBT 1.0s（避免被限流）
- YBT `--all` 会爬取 3700+ 题，建议分批进行
- 生成的 `.problem.md` 文件使用 UTF-8 编码，换行符为 LF
