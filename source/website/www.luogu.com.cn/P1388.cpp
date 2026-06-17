#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[20];
int dp[20][20][20];

void input() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
}

void process() {
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][i][0] = a[i];
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int m = 0; m <= min(k, len - 1); m++) {
                int &cur = dp[l][r][m] = -1;
                for (int p = l; p < r; p++) {
                    int leftMax  = p - l;
                    int rightMax = r - p - 1;
                    for (int m1 = max(0, m - rightMax); m1 <= min(m, leftMax); m1++) {
                        int m2 = m - m1;
                        if (dp[l][p][m1] != -1 && dp[p + 1][r][m2] != -1)
                            cur = max(cur, dp[l][p][m1] + dp[p + 1][r][m2]);
                    }
                    if (m >= 1) {
                        for (int m1 = max(0, m - 1 - rightMax); m1 <= min(m - 1, leftMax); m1++) {
                            int m2 = m - 1 - m1;
                            if (dp[l][p][m1] != -1 && dp[p + 1][r][m2] != -1)
                                cur = max(cur, dp[l][p][m1] * dp[p + 1][r][m2]);
                        }
                    }
                }
            }
        }
    }
}

void output() { printf("%d\n", dp[1][n][k]); }

int main() {
    input();
    process();
    output();
    return 0;
}
