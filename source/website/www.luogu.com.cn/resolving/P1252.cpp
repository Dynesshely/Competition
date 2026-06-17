#include <bits/stdc++.h>
using namespace std;

int t[6][11];
int dp[6][26];
int pre[6][26];
int ans[6];

void input() {
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 10; j++)
            scanf("%d", &t[i][j]);
}

void process() {
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= 5; i++)
        for (int j = i; j <= 25; j++)
            for (int k = 1; k <= 10 && k <= j; k++)
                if (dp[i - 1][j - k] != 0x3f3f3f3f) {
                    int val = dp[i - 1][j - k] + t[i][k];
                    if (val < dp[i][j]) {
                        dp[i][j]  = val;
                        pre[i][j] = k;
                    }
                }
    int cur = 25;
    for (int i = 5; i >= 1; i--) {
        ans[i] = pre[i][cur];
        cur -= ans[i];
    }
}

void output() {
    printf("%d\n", dp[5][25]);
    for (int i = 1; i <= 5; i++)
        printf("%d%c", ans[i], i == 5 ? '\n' : ' ');
}

int main() {
    input();
    process();
    output();
    return 0;
}
