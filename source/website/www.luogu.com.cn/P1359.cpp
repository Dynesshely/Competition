#include <bits/stdc++.h>
using namespace std;

int n;
int r[205][205];
int dp[205];

void input() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            scanf("%d", &r[i][j]);
}

void process() {
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (dp[j] + r[j][i] < dp[i])
                dp[i] = dp[j] + r[j][i];
}

void output() { printf("%d\n", dp[n]); }

int main() {
    input();
    process();
    output();
    return 0;
}
