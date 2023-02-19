## 2022-02-27 Round5
### Overview
* Start: 14:00
* End: 17:30
* P: 4

### 烽火石 (tower)
#### Overview
* TPP: 1s
* MFA: 512 MB
* Filter: .in .out
* O2: Enabled

#### Path

#### Summary
##### In Testing
* Time Use:
    * Read: NaN
    * 1st NaN
    * Debug: NaN
    * Total: NaN
* Comment: Null

### 博弈 (game)
#### Overview
* TPP: 1s
* MFA: 512 MB
* Filter: .in .out
* O2: Enabled

#### Path

#### Summary
##### In Testing
* Time Use:
    * Read: NaN
    * 1st NaN
    * Debug: NaN
    * Total: NaN
* Comment: Null

### 染色 (draw)
#### Overview
* TPP: 1s
* MFA: 512 MB
* Filter: .in .out
* O2: Enabled

#### Path
1. 14:18 - 开始审题
2. 14:29 - 完整理解，开始解答 (类似于括号配对)
3. 14:34 - 完成输入和数据的初步处理部分
4. 14:46 - 第一版完成，思路是正确的，但出现一个问题：按数值记录坐标判断会漏掉已经统计过的数字但单独出现在嵌套内的情况，不能通过简单凭数值判断，因当通过下标
5. 14:53 - 新思路：通过双指针从两头向中间寻找嵌套的配对
6. 15:01 - 双指针设计有误，开始重写
7. 15:06 - 发现需要递归分块求解
8. 15:10 - 完成，能过样例了，开始造数据检验
9. 15:12 - 发现问题，没有更新区块内同数据的区块
10. 15:18 - 解决[9]中的问题，发现新问题：更新区块内数据不能过度更新，问题数据：
```
10
1 8 1 1 1 1 8 6 6 1
```
问题输出：3, 正确输出: 4
11. 15:23 - 解决[10]中的问题，发现新问题：取消连块更新后发现，原有区块易覆盖，问题数据：
```
9
1 8 1 1 1 1 8 6 6
```
问题输出：3, 正确输出：4
12. 15:35 - 解决[11]中的问题，发现新问题：没有考虑多起点，问题数据：
```
10
1 8 1 2 1 1 2 1 7 8
```
问题输出：7, 正确输出：6
13. 15:44 解决[12]中的问题，没有发现新问题，就这样吧

#### Summary
##### In Testing
* Time Use:
    * Read: 11 min
    * 1st Version: 41 min
    * Debug: 34 min
    * Total: 1h 26min
* Comment: 思考问题不够全面，用时太久，不能快速找出最优解
* Plan: 50pts
* 时间复杂度: O(n*nlogn) [瞎猜的]
* 空间复杂度: NaN

##### After Testing

### 排列计数 (permutation)
#### Overview
* TPP: 1s
* MFA: 512 MB
* Filter: .in .out
* O2: Enabled

#### Path

#### Summary
##### In Testing
* Time Use:
    * Read: NaN
    * 1st NaN
    * Debug: NaN
    * Total: NaN
* Comment: Null
