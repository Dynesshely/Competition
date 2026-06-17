#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 5000;
const int INF    = 0x3f3f3f3f;

int n, a[1005], b[1005];
int dp[10005], ndp[10005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i], &b[i]);
}

void process() {
    memset(dp, 0x3f, sizeof(dp));
    dp[OFFSET] = 0;
    for (int i = 0; i < n; ++i) {
        int d = a[i] - b[i];
        memset(ndp, 0x3f, sizeof(ndp));
        for (int s = -OFFSET; s <= OFFSET; ++s) {
            int idx = s + OFFSET;
            if (dp[idx] == INF)
                continue;
            int ns1 = s + d, ns2 = s - d;
            if (ns1 >= -OFFSET && ns1 <= OFFSET)
                ndp[ns1 + OFFSET] = min(ndp[ns1 + OFFSET], dp[idx]);
            if (ns2 >= -OFFSET && ns2 <= OFFSET)
                ndp[ns2 + OFFSET] = min(ndp[ns2 + OFFSET], dp[idx] + 1);
        }
        memcpy(dp, ndp, sizeof(dp));
    }
}

void output() {
    for (int diff = 0; diff <= OFFSET; ++diff) {
        int ans = INF;
        if (dp[OFFSET + diff] < ans)
            ans = dp[OFFSET + diff];
        if (dp[OFFSET - diff] < ans)
            ans = dp[OFFSET - diff];
        if (ans < INF) {
            printf("%d\n", ans);
            return;
        }
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
