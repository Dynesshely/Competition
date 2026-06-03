## 编码

### 代码风格

#### C++

1. 始终使用 bits/stdc++.h 头文件，不要别的头文件
2. 使用 using namespace std;
3. 始终使用 printf/scanf 并从 stdin 和 stdou 进行读写，若有 freopen 等代码一定要去掉
4. 标识符符合小驼峰规则
5. 函数命名遵从 doSomething 风格，对于如 dfs 等算法函数可以直接使用小写原名
6. 变量命名用缩写但尽可能保留含义如：visited -> via, row -> r, col -> c 等，偶尔可以保留全称如：width, height, x, y, pos_x, pos_y 等
7. 尽量少用宏，如果提供的代码包含宏，请全部展开
8. 不要有任何注释内容
9. 不要有任何调试输出
10. 不要有任何与 AC 题目无关的代码（如测试代码、模板代码等）
11. 对于流程明显的题目，使用 input(), process(), output() 三段式结构，其余计算与输出同步进行的题目除外
12. 对于只有一条语句的 for, if, else, while 等控制结构，去掉大括号来压行
