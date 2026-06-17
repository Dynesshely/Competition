#include <bits/stdc++.h>
using namespace std;

int n, m, k, val[205][205], isY[205][205], pool0[205][205], bonus0[205][205], pool1[205][205], bonus1[205][205], score[205][205], dp[205][3], ndp[205][3];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            char c;
            scanf("%d %c", &val[i][j], &c);
            isY[i][j] = (c == 'Y');
        }
    for (int col = 1; col <= m; ++col) {
        int sc = 0, bonus = 0, pool = 0;
        pool0[col][0] = bonus0[col][0] = 0;
        pool1[col][0]                  = 0;
        bonus1[col][0]                 = 1;
        bonus = 0, pool = 0;
        for (int row = n, pos = 1; row >= 1; --row, ++pos) {
            sc += val[row][col];
            score[col][pos] = sc;
            {
                if (bonus > 0)
                    --bonus;
                else
                    ++pool;
                if (isY[row][col])
                    ++bonus;
                pool0[col][pos]  = pool;
                bonus0[col][pos] = bonus;
            }
            {
                int b = bonus1[col][pos - 1];
                int p = pool1[col][pos - 1];
                if (b > 0)
                    --b;
                else
                    ++p;
                if (isY[row][col])
                    ++b;
                pool1[col][pos]  = p;
                bonus1[col][pos] = b;
            }
        }
    }
    for (int j = 0; j <= k; ++j)
        dp[j][0] = dp[j][1] = dp[j][2] = -0x3f3f3f3f;
    dp[0][0] = 0;
    for (int col = 1; col <= m; ++col) {
        for (int j = 0; j <= k; ++j)
            ndp[j][0] = dp[j][0], ndp[j][1] = dp[j][1], ndp[j][2] = dp[j][2];
        for (int t = 1; t <= n; ++t) {
            int p0 = pool0[col][t], b0 = bonus0[col][t];
            int p1 = pool1[col][t], b1 = bonus1[col][t];
            int sc = score[col][t];
            for (int j = 0; j + p0 <= k; ++j) {
                if (dp[j][0] >= 0) {
                    if (b0 == 0)
                        ndp[j + p0][0] = max(ndp[j + p0][0], dp[j][0] + sc);
                    if (b0 == 1)
                        ndp[j + p0][1] = max(ndp[j + p0][1], dp[j][0] + sc);
                }
                if (dp[j][2] >= 0) {
                    if (b0 == 0)
                        ndp[j + p0][2] = max(ndp[j + p0][2], dp[j][2] + sc);
                    if (b0 == 1)
                        ndp[j + p0][0] = max(ndp[j + p0][0], dp[j][2] + sc);
                }
            }
            for (int j = 0; j + p1 <= k; ++j) {
                if (dp[j][1] >= 0) {
                    if (b1 == 0)
                        ndp[j + p1][0] = max(ndp[j + p1][0], dp[j][1] + sc);
                    if (b1 == 1)
                        ndp[j + p1][1] = max(ndp[j + p1][1], dp[j][1] + sc);
                }
                if (dp[j][0] >= 0) {
                    if (b1 == 0)
                        ndp[j + p1][2] = max(ndp[j + p1][2], dp[j][0] + sc);
                    if (b1 == 1)
                        ndp[j + p1][0] = max(ndp[j + p1][0], dp[j][0] + sc);
                }
            }
        }
        for (int j = 0; j <= k; ++j)
            dp[j][0] = ndp[j][0], dp[j][1] = ndp[j][1], dp[j][2] = ndp[j][2];
    }
    int ans = 0;
    for (int j = 0; j <= k; ++j)
        ans = max(ans, max(dp[j][0], dp[j][1]));
    printf("%d\n", ans);
    return 0;
}
