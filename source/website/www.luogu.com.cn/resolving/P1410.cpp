#include <bits/stdc++.h>
using namespace std;

int n, a[2010];

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int                 m   = n / 2;
        const int           INF = 2e9;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
        dp[1][1] = -1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= min(i - 1, m); j++) {
                if (dp[i - 1][j] == INF)
                    continue;
                if (a[i] > a[i - 1])
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j]);
                if (a[i] > dp[i - 1][j]) {
                    int nxt = i - j;
                    if (nxt <= m)
                        dp[i][nxt] = min(dp[i][nxt], a[i - 1]);
                }
            }
        }
        printf("%s\n", dp[n][m] == INF ? "No!" : "Yes!");
    }
    return 0;
}
