#include <bits/stdc++.h>
using namespace std;

int                            n, m, ans;
vector<vector<pair<int, int>>> adj;
vector<bool>                   via;

void dfs(int u, int len) {
    ans = max(ans, len);
    for (auto &e : adj[u]) {
        int v = e.first, w = e.second;
        if (!via[v]) {
            via[v] = true;
            dfs(v, len + w);
            via[v] = false;
        }
    }
}

void input() {
    scanf("%d%d", &n, &m);
    adj.resize(n + 1);
    via.resize(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
}

void process() {
    for (int i = 1; i <= n; i++) {
        fill(via.begin(), via.end(), false);
        via[i] = true;
        dfs(i, 0);
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
