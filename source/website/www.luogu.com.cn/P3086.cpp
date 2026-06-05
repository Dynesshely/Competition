#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int  n, up[N][N], lef[N][N], ans, dp[N][N][N];
char grid[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", grid[i] + 1);
        for (int j = 1; j <= n; ++j)
            if (grid[i][j] == '.')
                up[i][j] = up[i - 1][j] + 1, lef[i][j] = lef[i][j - 1] + 1;
    }
    for (int l = 1; l <= n; ++l)
        for (int r = l + 2; r <= n; ++r) {
            int t = 1;
            for (int h = 1; h <= n; ++h) {
                if (l < r - lef[h][r] + 1)
                    continue;
                while ((t < h - min(up[h][l], up[h][r]) + 1 || l <= r - lef[t][r] + 1) && t + 2 <= h)
                    ++t;
                if (t + 2 <= h)
                    dp[h][l][r] = (r - l - 1) * (h - t - 1);
            }
        }
    for (int i = 1; i <= n; ++i)
        for (int len = 4; len <= n; ++len) {
            for (int l = 1; l + len - 1 <= n; ++l)
                dp[i][l][l + len - 1] = max(dp[i][l][l + len - 1], dp[i][l][l + len - 2]);
            for (int r = n; r - len + 1 >= 1; --r)
                dp[i][r - len + 1][r] = max(dp[i][r - len + 1][r], dp[i][r - len + 2][r]);
        }
    for (int l = 1; l <= n; ++l)
        for (int r = l + 2; r <= n; ++r) {
            int t = n;
            for (int h = n; h >= 1; --h) {
                if (l < r - lef[h][r] + 1)
                    continue;
                while ((h < t - min(up[t][l], up[t][r]) + 1 || l <= r - lef[t][r] + 1) && h + 2 <= t)
                    --t;
                if (h + 2 <= t)
                    ans = max((r - l - 1) * (t - h - 1) * dp[h][l][r], ans);
            }
        }
    if (ans)
        printf("%d", ans);
    else
        puts("-1");
    return 0;
}
