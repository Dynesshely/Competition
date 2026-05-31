#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// P1002 [NOIP 2002 普及组] 过河卒
// 马控点不可达，卒子只能向右或向下

int main() {
    int bx, by, hx, hy;
    scanf("%d%d%d%d", &bx, &by, &hx, &hy);

    vector dp(bx + 2, vector<ll>(by + 2, 0));
    vector blocked(bx + 2, vector<bool>(by + 2, false));

    // 马控的 9 个位置
    const int dx[] = {0, 1, 1, 2, 2, -1, -1, -2, -2};
    const int dy[] = {0, 2, -2, 1, -1, 2, -2, 1, -1};
    for (int k = 0; k < 9; ++k) {
        int x = hx + dx[k], y = hy + dy[k];
        if (x >= 0 && x <= bx && y >= 0 && y <= by)
            blocked[x][y] = true;
    }

    if (!blocked[0][0]) dp[0][0] = 1;
    for (int i = 0; i <= bx; ++i)
        for (int j = 0; j <= by; ++j) {
            if (blocked[i][j]) continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }

    printf("%lld\n", dp[bx][by]);
    return 0;
}
