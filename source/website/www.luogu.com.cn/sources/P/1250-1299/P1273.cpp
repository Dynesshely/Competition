#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int                            n, m;
vector<vector<pair<int, int>>> adj;
vector<int>                    pay;
vector<vector<int>>            dp;

void input() {
    scanf("%d%d", &n, &m);
    adj.resize(n + 1);
    for (int i = 1; i <= n - m; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int a, c;
            scanf("%d%d", &a, &c);
            adj[i].push_back({a, c});
        }
    }
    pay.resize(n + 1, 0);
    for (int i = n - m + 1; i <= n; i++)
        scanf("%d", &pay[i]);
    dp.resize(n + 1);
}

int dfs(int u) {
    if (u > n - m) {
        dp[u].resize(2, -INF);
        dp[u][0] = 0;
        dp[u][1] = pay[u];
        return 1;
    }
    dp[u].push_back(0);
    int sz = 0;
    for (auto &edge : adj[u]) {
        int         v = edge.first, c = edge.second;
        int         childSz = dfs(v);
        vector<int> newdp(sz + childSz + 1, -INF);
        for (int k = 0; k <= sz; k++) {
            if (dp[u][k] == -INF)
                continue;
            newdp[k] = max(newdp[k], dp[u][k]);
            for (int j = 1; j <= childSz; j++) {
                if (dp[v][j] == -INF)
                    continue;
                newdp[k + j] = max(newdp[k + j], dp[u][k] + dp[v][j] - c);
            }
        }
        dp[u] = newdp;
        sz += childSz;
    }
    return sz;
}

void process() { dfs(1); }

void output() {
    for (int k = (int)dp[1].size() - 1; k >= 0; k--)
        if (dp[1][k] >= 0) {
            printf("%d\n", k);
            break;
        }
}

int main() {
    input();
    process();
    output();
    return 0;
}
