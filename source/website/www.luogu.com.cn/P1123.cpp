#include <bits/stdc++.h>
using namespace std;

int T, n, m, a[8][8], dp[8][1 << 8];

int sumRow(int r, int mask) {
    int s = 0;
    for (int c = 0; c < m; c++)
        if (mask & (1 << c))
            s += a[r][c];
    return s;
}

bool noAdjRow(int mask) { return (mask & (mask << 1)) == 0; }

bool noAdjCol(int mask, int prev) { return (mask & (prev | (prev << 1) | (prev >> 1))) == 0; }

void input() { scanf("%d", &T); }

void process() {
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
        int states = 1 << m;
        memset(dp, 0, sizeof(dp));
        for (int mask = 0; mask < states; mask++)
            if (noAdjRow(mask))
                dp[0][mask] = sumRow(0, mask);
        for (int r = 1; r < n; r++) {
            for (int mask = 0; mask < states; mask++) {
                if (!noAdjRow(mask))
                    continue;
                int s = sumRow(r, mask), best = 0;
                for (int prev = 0; prev < states; prev++) {
                    if (!noAdjRow(prev))
                        continue;
                    if (noAdjCol(mask, prev))
                        best = max(best, dp[r - 1][prev]);
                }
                dp[r][mask] = best + s;
            }
        }
        int ans = 0;
        for (int mask = 0; mask < states; mask++)
            ans = max(ans, dp[n - 1][mask]);
        printf("%d\n", ans);
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
