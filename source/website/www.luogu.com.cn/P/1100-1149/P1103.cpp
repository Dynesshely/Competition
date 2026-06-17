#include <bits/stdc++.h>
using namespace std;

int            n, k, m, dp[105][105];
pair<int, int> a[105];

void input() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
}

void process() {
    sort(a + 1, a + n + 1);
    m = n - k;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][1] = 0;
    for (int j = 2; j <= m; j++)
        for (int i = j; i <= n; i++)
            for (int t = j - 1; t < i; t++)
                dp[i][j] = min(dp[i][j], dp[t][j - 1] + abs(a[i].second - a[t].second));
}

void output() {
    int ans = 1e9;
    for (int i = m; i <= n; i++)
        ans = min(ans, dp[i][m]);
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
