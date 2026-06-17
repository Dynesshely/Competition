#include <bits/stdc++.h>
using namespace std;

int  n;
char w[16][105];
int  l[16];
int  dp[1 << 16][16];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", w[i]);
        l[i] = strlen(w[i]);
    }
}

void process() {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = l[i];
    for (int mask = 1; mask < (1 << n); mask++)
        for (int last = 0; last < n; last++) {
            if (dp[mask][last] == -1)
                continue;
            for (int nxt = 0; nxt < n; nxt++) {
                if (mask & (1 << nxt))
                    continue;
                if (w[last][l[last] - 1] == w[nxt][0]) {
                    int newMask = mask | (1 << nxt);
                    if (dp[newMask][nxt] < dp[mask][last] + l[nxt])
                        dp[newMask][nxt] = dp[mask][last] + l[nxt];
                }
            }
        }
}

void output() {
    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            if (dp[mask][i] > ans)
                ans = dp[mask][i];
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
