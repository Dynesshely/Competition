#include <bits/stdc++.h>
using namespace std;

// P1007 独木桥
// 相遇转身 等价于 互相穿过（身份交换）
// 最短时间 = max(每个士兵到最近端点的距离)
// 最长时间 = max(每个士兵到最远端点的距离)

int main() {
    int L, N;
    scanf("%d%d", &L, &N);
    int min_ans = 0, max_ans = 0;
    for (int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        int to_left = x;           // 到左端点 0 的距离
        int to_right = L + 1 - x;  // 到右端点 L+1 的距离
        min_ans = max(min_ans, min(to_left, to_right));
        max_ans = max(max_ans, max(to_left, to_right));
    }
    printf("%d %d\n", min_ans, max_ans);
    return 0;
}
