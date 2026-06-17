#include <bits/stdc++.h>
using namespace std;

int coin[1005][1005], cost[1005], dp[1005];

int main() {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &coin[i][j]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &cost[i]);
    memset(dp, 0xcf, sizeof(dp));
    dp[0] = 0;
    for (int t = 1; t <= m; ++t) {
        for (int j = 1; j <= n; ++j) {
            int pre = j - 1;
            if (pre == 0)
                pre = n;
            int sum = coin[pre][t];
            for (int k = 1; k <= p; ++k) {
                if (t - k < 0)
                    break;
                dp[t] = max(dp[t], dp[t - k] + sum - cost[pre]);
                --pre;
                if (pre == 0)
                    pre = n;
                sum += coin[pre][t - k];
            }
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}
