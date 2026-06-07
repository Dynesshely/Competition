#include <bits/stdc++.h>
using namespace std;

int n, dist[20][20], dp[1 << 20][20];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);
}

void process() {
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        if (!(mask & 1))
            continue;
        for (int u = 0; u < n; u++) {
            if (!(mask >> u & 1))
                continue;
            int cur = dp[mask][u];
            if (cur == 0x3f3f3f3f)
                continue;
            for (int v = 0; v < n; v++) {
                if (mask >> v & 1)
                    continue;
                int nmask = mask | (1 << v);
                int nv    = cur + dist[u][v];
                if (nv < dp[nmask][v])
                    dp[nmask][v] = nv;
            }
        }
    }
    int full = (1 << n) - 1;
    int ans  = 0x3f3f3f3f;
    for (int u = 1; u < n; u++) {
        int val = dp[full][u] + dist[u][0];
        if (val < ans)
            ans = val;
    }
    printf("%d\n", ans);
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
