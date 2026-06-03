#include <cstdio>
#include <algorithm>
using namespace std;

int a[205];
long long dp[205][205];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= 2 * n; ++i) {
            int j = i + len - 1;
            dp[i][j] = 0;
            for (int k = i; k < j; ++k) {
                long long val = dp[i][k] + dp[k + 1][j]
                              + (long long)a[i] * a[k + 1] * a[j + 1];
                if (val > dp[i][j]) dp[i][j] = val;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        if (dp[i][i + n - 1] > ans) ans = dp[i][i + n - 1];
    printf("%lld\n", ans);
    return 0;
}
