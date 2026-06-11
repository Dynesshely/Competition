#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int               n, m, a[25], b[25];
ll                dp[205];
ll                cost[25][205];
void              input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &a[i], &b[i]);
}
void process() {
    for (int i = 1; i <= m; i++)
        for (int k = 1; k <= n; k++) {
            ll val = 1;
            for (int p = 1; p <= b[i]; p++)
                val *= k;
            cost[i][k] = a[i] * val;
        }
    for (int i = 1; i <= n; i++)
        dp[i] = 1e18;
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = n; j >= 0; j--)
            for (int k = 1; k <= n - j; k++)
                dp[j + k] = min(dp[j + k], dp[j] + cost[i][k]);
}
void output() { printf("%lld\n", dp[n]); }
int  main() {
    input();
    process();
    output();
    return 0;
}
