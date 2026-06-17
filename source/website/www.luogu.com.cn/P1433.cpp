#include <bits/stdc++.h>
using namespace std;

int    n;
double x[20], y[20], dist[20][20], dp[1 << 15][15];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &x[i], &y[i]);
}

void process() {
    x[n] = y[n] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    for (int mask = 0; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            dp[mask][i] = 1e9;
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = dist[n][i];
    for (int mask = 0; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                for (int j = 0; j < n; j++)
                    if (!(mask & (1 << j)))
                        dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dist[i][j]);
}

void output() {
    double ans  = 1e9;
    int    full = (1 << n) - 1;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[full][i]);
    printf("%.2f\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
