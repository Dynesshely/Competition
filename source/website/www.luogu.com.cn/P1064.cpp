#include <cstdio>
#include <algorithm>
using namespace std;

int v[65], p[65], q[65];
int dp[32005];
int group[65][5]; // group[i] = {main_price, main_val, +att1_price, +att1_val, ...} up to 4 combos

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &v[i], &p[i], &q[i]);

    for (int i = 1; i <= m; ++i) {
        if (q[i] != 0) continue; // process only main items
        int cnt = 0;
        int prices[4] = {0}, vals[4] = {0};
        // option 0: main only
        prices[cnt] = v[i];
        vals[cnt] = v[i] * p[i];
        ++cnt;
        // find attachments for this main
        for (int j = 1; j <= m; ++j) {
            if (q[j] == i) {
                int cur = cnt;
                for (int t = 0; t < cur; ++t) {
                    prices[cnt] = prices[t] + v[j];
                    vals[cnt] = vals[t] + v[j] * p[j];
                    ++cnt;
                }
            }
        }
        // 0-1 knapsack for this group (descending to avoid reuse)
        for (int w = n; w >= 0; --w)
            for (int t = 0; t < cnt; ++t)
                if (w >= prices[t])
                    dp[w] = max(dp[w], dp[w - prices[t]] + vals[t]);
    }
    printf("%d\n", dp[n]);
    return 0;
}
