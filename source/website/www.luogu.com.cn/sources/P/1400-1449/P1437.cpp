#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int       n, m;
int       a[55][55];
int       sum[55][55];
int       dp[2][55][1300];
int       sm[55][1300];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i + 1; j++)
            scanf("%d", &a[i][j]);
}

void process() {
    for (int j = 1; j <= n; j++) {
        int c = n - j + 1;
        for (int i = 1; i <= n - j + 1; i++)
            sum[c][i] = sum[c][i - 1] + a[i][j];
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= m; k++)
                dp[i][j][k] = -INF;
    dp[0][0][0] = 0;
    for (int c = 1; c <= n; c++) {
        int cur = c & 1, pre = cur ^ 1;
        for (int k = 0; k <= m; k++)
            for (int t = 0; t <= n; t++)
                sm[t][k] = -INF;
        for (int k = 0; k <= m; k++)
            for (int t = c - 1; t >= 0; t--)
                sm[t][k] = max(dp[pre][t][k], sm[t + 1][k]);
        for (int k = 0; k <= m; k++)
            for (int t = 0; t <= c && t <= k; t++) {
                int val  = sum[c][t];
                int need = t == 0 ? 0 : t - 1;
                if (sm[need][k - t] > -INF / 2)
                    dp[cur][t][k] = val + sm[need][k - t];
            }
    }
}

void output() {
    int ans = 0;
    for (int k = 0; k <= m; k++)
        for (int t = 0; t <= n; t++)
            ans = max(ans, dp[n & 1][t][k]);
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
