#include <bits/stdc++.h>
using namespace std;

int  k;
char a[2010], b[2010];
int  n, m;
int  dp[2010][2010];

void input() {
    scanf("%s%s%d", a + 1, b + 1, &k);
    n = strlen(a + 1);
    m = strlen(b + 1);
}

void process() {
    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i - 1][0] + k;
    for (int j = 1; j <= m; j++)
        dp[0][j] = dp[0][j - 1] + k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = min(dp[i - 1][j - 1] + abs(a[i] - b[j]), min(dp[i - 1][j] + k, dp[i][j - 1] + k));
}

void output() { printf("%d\n", dp[n][m]); }

int main() {
    input();
    process();
    output();
    return 0;
}
