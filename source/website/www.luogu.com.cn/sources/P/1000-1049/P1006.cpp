#include <bits/stdc++.h>
using namespace std;

// P1006 [NOIP 2008 提高组] 传纸条
// 两人同时从 (1,1) 到 (m,n)，路径不可重叠，最大化友好值
// dp[step][x1][x2], step = x+y

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    vector a(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);

    // dp[step][x1][x2]
    const int S = m + n;
    vector dp(S + 1, vector(m + 1, vector<int>(m + 1, -1)));
    dp[2][1][1] = a[1][1];

    for (int s = 2; s < S; ++s) {
        for (int x1 = 1; x1 <= m && x1 < s; ++x1) {
            int y1 = s - x1;
            if (y1 < 1 || y1 > n) continue;
            for (int x2 = 1; x2 <= m && x2 < s; ++x2) {
                int y2 = s - x2;
                if (y2 < 1 || y2 > n) continue;
                if (dp[s][x1][x2] < 0) continue;

                for (int d1 = 0; d1 < 2; ++d1) {
                    int nx1 = x1 + d1, ny1 = y1 + (1 - d1);
                    if (nx1 > m || ny1 > n) continue;
                    for (int d2 = 0; d2 < 2; ++d2) {
                        int nx2 = x2 + d2, ny2 = y2 + (1 - d2);
                        if (nx2 > m || ny2 > n) continue;
                        if (nx1 == nx2 && ny1 == ny2 && !(nx1 == m && ny1 == n))
                            continue; // 路径不可重叠（除终点）
                        int add = a[nx1][ny1] + a[nx2][ny2];
                        if (nx1 == nx2 && ny1 == ny2) add /= 2;
                        dp[s + 1][nx1][nx2] = max(
                            dp[s + 1][nx1][nx2], dp[s][x1][x2] + add);
                    }
                }
            }
        }
    }

    printf("%d\n", max(0, dp[S][m][m]));
    return 0;
}
