#include <bits/stdc++.h>
using namespace std;

int n, c;
int pos[55], w[55], pref[55];
int dp[55][55][2];

void input() {
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &pos[i], &w[i]);
        pref[i] = pref[i - 1] + w[i];
    }
}

void process() {
    memset(dp, 0x3f, sizeof(dp));
    dp[c][c][0] = dp[c][c][1] = 0;
    int total                 = pref[n];
    for (int len = 2; len <= n; len++)
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (l > c || r < c)
                continue;
            dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][0] + (pos[l + 1] - pos[l]) * (total - (pref[r] - pref[l])));
            dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][1] + (pos[r] - pos[l]) * (total - (pref[r] - pref[l])));
            dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][0] + (pos[r] - pos[l]) * (total - (pref[r - 1] - pref[l - 1])));
            dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][1] + (pos[r] - pos[r - 1]) * (total - (pref[r - 1] - pref[l - 1])));
        }
}

void output() { printf("%d\n", min(dp[1][n][0], dp[1][n][1])); }

int main() {
    input();
    process();
    output();
    return 0;
}
