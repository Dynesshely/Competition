#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int         n, p;
vector<int> g[155];
int         dp[155][155];
int         sz[155];

void dfs(int u, int par) {
    dp[u][1] = 0;
    int cur  = 1;
    for (int v : g[u]) {
        if (v == par)
            continue;
        dfs(v, u);
        int top = min(cur, p);
        for (int k = top; k >= 1; --k) {
            int old  = dp[u][k];
            dp[u][k] = old + 1;
            int lim  = min(sz[v], p - k);
            for (int s = 1; s <= lim; ++s)
                dp[u][k + s] = min(dp[u][k + s], old + dp[v][s]);
        }
        cur += sz[v];
    }
    sz[u] = cur;
}

void input() {
    scanf("%d%d", &n, &p);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void process() {
    memset(dp, 0x3f, sizeof(dp));
    dfs(1, 0);
}

void output() {
    int ans = dp[1][p];
    for (int i = 2; i <= n; ++i)
        if (dp[i][p] + 1 < ans)
            ans = dp[i][p] + 1;
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
