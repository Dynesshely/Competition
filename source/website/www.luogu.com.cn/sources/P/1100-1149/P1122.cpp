#include <bits/stdc++.h>
using namespace std;

const int MAXN = 16010;

int         n, a[MAXN], dp[MAXN], ans;
vector<int> g[MAXN];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dfs(int u, int fa) {
    dp[u] = a[u];
    for (int v : g[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        if (dp[v] > 0)
            dp[u] += dp[v];
    }
}

void process() {
    dfs(1, 0);
    ans = dp[1];
    for (int i = 2; i <= n; i++) {
        if (dp[i] > ans)
            ans = dp[i];
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
