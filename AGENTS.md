## 编码

### 代码风格

#### C++

1. 始终使用 bits/stdc++.h 头文件，不要别的头文件
2. 使用 using namespace std;
3. 始终使用 printf/scanf 并从 stdin 和 stdou 进行读写，若有 freopen 等代码一定要去掉
   但对于部分特殊题目如提交答案题，你根据用户的指示来决定是否使用 freopen 来读写文件
4. 标识符符合小驼峰规则
5. 函数命名遵从 doSomething 风格，对于如 dfs 等算法函数可以直接使用小写原名
6. 变量命名用缩写但尽可能保留含义如：visited -> via, row -> r, col -> c 等，偶尔可以保留全称如：width, height, x, y, pos_x, pos_y 等
7. 尽量少用宏，如果提供的代码包含宏，请全部展开
8. 不要有任何注释内容
9. 不要有任何调试输出
10. 不要有任何与 AC 题目无关的代码（如测试代码、模板代码等）
11. 对于流程明显的题目，使用 input(), process(), output() 三段式结构，其余计算与输出同步进行的题目除外
12. 对于只有一条语句的 for, if, else, while 等控制结构，去掉大括号来压行

## 智能解题流程

### 从零到 AC

1. **爬取题目** — `python3 website/scripts/luogu.py <PID>` 生成 `.problem.md`（若不存在）
2. **编写代码** — 遵循本文件代码风格约定编写 `.cpp`
3. **格式化代码** — 编写后必须执行 `clang-format -i <.cpp>`（配置位于仓库根目录 `.clang-format`），确保代码风格一致
4. **编译测试** — `g++ -std=c++17 -O2 -fsyntax-only` 编译检查语法，用题面样例验证正确性
5. **在线评测** — 确保 daemon 已启动且浏览器扩展已连接后，使用 `luogu submit <.cpp>` 提交洛谷在线评测：
   - **AC 100 分**：自动进入步骤 6 编写题解并提交 git，无需人工等待验收
   - **非 AC**：根据题目难度决策：
     - 入门 / 普及−：重试一次，修正代码后再次提交（最多 3 次尝试）
     - 提高+ / 省选 / NOI-：放弃本轮，移入 `documents/high-difficulty.md` 高难度列表，等待后续集中攻克
6. **编写题解** — AC 后立即编写 `.explain.md`（格式见下方题解规范）
7. **逐题提交** — 每道题单独 `git commit -m "feat(AC <PID> @ 洛谷): implemented code of <PID> from 洛谷"`，提交内容包含 `.cpp` + `.problem.md` + `.explain.md` 及关联的测试数据（`_<id>.in/.ans`）
8. **汇报结果** — 每道题完成后汇报 AC 结果；对于移入高难度列表的题目，说明失败原因（WA/TLE/RE/CE）及得分

### 批量验收流程

1. **判断评测需求** — 检查用户是否明确表示这批题目已 AC：
   - **用户已声明 AC**：跳过在线评测步骤 2，直接进入步骤 3 编写题解
   - **未声明 AC / 不确定**：执行全部流程
2. **批量在线评测** — 使用 `luogu batch <dir> --export markdown` 批量提交评测，获取所有题目的评测结果
3. **结果分流** — 根据评测结果分类处理：
   - **AC 100 分**：自动进入步骤 4 编写题解并提交
   - **非 AC（入门/普及−）**：代码需修正，最多重试 3 次，仍不通过则移入高难度列表
   - **非 AC（提高+/省选/NOI-）**：直接移入 `documents/high-difficulty.md`
4. **编写题解** — AC 题目检查 `.explain.md` 是否存在：
   - **已有题解** + 三文件齐全：直接提交
   - **缺题解**：读取 `.cpp` 和 `.problem.md`，编写题解后提交
   - **缺 `.problem.md`**：先爬取题目再编写题解
5. **并行加速** — 缺题解数量较大时（>10 道），用后台 Agent 分组并行编写，每 Agent 10~16 道为宜
6. **逐题提交** — AC 题目按编号顺序逐题 `git commit`，提交信息格式一致
7. **测试数据** — 检查是否存在 `_<id>.in/.ans` 文件，一并提交
8. **汇总报告** — 全部完成后输出：AC 题目数、高难度列表新增数、各题评测结果 Markdown 表

### 题解规范

`.explain.md` 统一格式：

```
# PXXXX [来源] 题解名称 题解

## 题目链接
- [洛谷 PXXXX](https://www.luogu.com.cn/problem/PXXXX)

## 题目大意
...

## 解题思路
...

## 代码实现
...

## 复杂度分析
- 时间复杂度：...
- 空间复杂度：...
```

### 代码改写流程

当用户要求按代码风格改写已有 `.cpp` 时：

1. 读取原代码和 `AGENTS.md` 规范
2. 逐条应用：展开宏、去注释、换 `scanf/printf`、小驼峰命名、`doSomething` 函数风格、单语句去大括号
3. 格式化：`clang-format -i <.cpp>`（配置位于仓库根目录 `.clang-format`）
4. 编译验证：`g++ -std=c++17 -O2 -fsyntax-only`
5. 不改动编译产物（`.out/.exe`）和测试数据

### 高难度题目列表

`documents/high-difficulty.md` 格式：

```markdown
| PID   | 题目名称 | 难度  | 失败原因 | 得分 | 记录日期   |
| ----- | -------- | ----- | -------- | ---- | ---------- |
| P1436 | ...      | 提高+ | WA       | 40   | 2026-06-19 |
| P1410 | ...      | 省选  | RE       | 100? | 2026-06-18 |
```

后续集中攻克时，逐题重新分析并提交评测。

### 洛谷 CLI 参考

```bash
# 环境准备（必须先启动 daemon 并在浏览器加载扩展）
# daemon 启动后确保扩展已连接（curl http://127.0.0.1:9527/api/health → wsConnected: true）

# 安装别名
./utils/luogu.sh --install

# 单题提交并等待 AC
luogu submit source/website/www.luogu.com.cn/P1001.cpp

# 批量评测（含 Markdown 汇总表）
luogu batch source/website/www.luogu.com.cn/ --export markdown

# 按范围筛选批量评测
luogu batch source/website/www.luogu.com.cn/ --include 'P10[0-9]{2}'
```
