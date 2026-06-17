#include <bits/stdc++.h>
using namespace std;

int n, m, d[10010], dp[10010][510];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
}

void process() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] < 0)
                continue;
            if (j < m && dp[i][j] + d[i + 1] > dp[i + 1][j + 1])
                dp[i + 1][j + 1] = dp[i][j] + d[i + 1];
            if (j == 0 && dp[i][0] > dp[i + 1][0])
                dp[i + 1][0] = dp[i][0];
            if (j > 0 && i + j <= n && dp[i][j] > dp[i + j][0])
                dp[i + j][0] = dp[i][j];
        }
}

void output() { printf("%d\n", dp[n][0]); }

int main() {
    input();
    process();
    output();
    return 0;
}
