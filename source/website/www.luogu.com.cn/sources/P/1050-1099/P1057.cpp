#include <cstdio>

int dp[35][35];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = dp[i - 1][j == 1 ? n : j - 1]
                     + dp[i - 1][j == n ? 1 : j + 1];
    printf("%d\n", dp[m][1]);
    return 0;
}
