#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], pre[110];
int mod10(int x) { return ((x % 10) + 10) % 10; }
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) { scanf("%d", &a[i]); a[i + n] = a[i]; }
    for (int i = 1; i <= 2 * n; ++i) pre[i] = pre[i - 1] + a[i];
    int ans_min = 1e9, ans_max = -1e9;
    for (int st = 1; st <= n; ++st) {
        vector dp(n + 1, vector<int>(m + 1, 1e9));
        vector dp2(n + 1, vector<int>(m + 1, -1e9));
        dp[0][0] = dp2[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int seg = mod10(pre[st + i - 1] - pre[st - 1]);
            dp[i][1] = dp2[i][1] = seg;
        }
        for (int j = 2; j <= m; ++j)
            for (int i = j; i <= n; ++i)
                for (int k = j - 1; k < i; ++k) {
                    int seg = mod10(pre[st + i - 1] - pre[st + k - 1]);
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] * seg);
                    dp2[i][j] = max(dp2[i][j], dp2[k][j - 1] * seg);
                }
        ans_min = min(ans_min, dp[n][m]);
        ans_max = max(ans_max, dp2[n][m]);
    }
    printf("%d\n%d\n", ans_min, ans_max);
    return 0;
}
