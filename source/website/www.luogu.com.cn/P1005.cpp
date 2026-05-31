#include <bits/stdc++.h>
using namespace std;

// P1005 [NOIP 2007 提高组] 矩阵取数游戏
// 每行独立区间 DP + __int128 高精度

using I = __int128;

void write(I x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    I pow2[81];
    pow2[0] = 1;
    for (int i = 1; i <= m; ++i) pow2[i] = pow2[i - 1] * 2;

    I total = 0;
    vector<int> a(m + 1);
    vector dp(m + 2, vector<I>(m + 2, 0));

    for (int row = 0; row < n; ++row) {
        for (int j = 1; j <= m; ++j) scanf("%d", &a[j]);

        for (int i = 1; i <= m; ++i)
            fill(dp[i].begin(), dp[i].end(), 0);

        for (int len = 1; len <= m; ++len) {
            for (int l = 1; l + len - 1 <= m; ++l) {
                int r = l + len - 1;
                int t = m - len + 1; // 第 t 次取数
                dp[l][r] = max(
                    dp[l + 1][r] + a[l] * pow2[t],
                    dp[l][r - 1] + a[r] * pow2[t]);
            }
        }
        total += dp[1][m];
    }

    write(total);
    putchar('\n');
    return 0;
}
