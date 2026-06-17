#include <bits/stdc++.h>
using namespace std;
int n, ans = 1e9;
vector<int> g[310], lev[310];
int fa[310], sz[310], depth[310], maxd;
void dfs_build(int u, int p, int d) {
    fa[u] = p; depth[u] = d; sz[u] = 1;
    maxd = max(maxd, d);
    lev[d].push_back(u);
    for (int v : g[u]) if (v != p) { dfs_build(v, u, d + 1); sz[u] += sz[v]; }
}
void search(int d, int infected, vector<int> &cur) {
    if (infected >= ans) return;
    if (d > maxd) { ans = min(ans, infected); return; }
    vector<int> nxt_lev;
    for (int u : cur)
        for (int v : g[u])
            if (v != fa[u]) nxt_lev.push_back(v);
    if (nxt_lev.empty()) { ans = min(ans, infected); return; }
    for (size_t i = 0; i < nxt_lev.size(); ++i) {
        vector<int> stay;
        int saved_sz = sz[nxt_lev[i]];
        for (size_t j = 0; j < nxt_lev.size(); ++j)
            if (j != i) stay.push_back(nxt_lev[j]);
        search(d + 1, infected + (int)stay.size(), stay);
    }
}
int main() {
    int p;
    scanf("%d%d", &n, &p);
    for (int i = 0; i < p; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs_build(1, 0, 1);
    vector<int> start = {1};
    search(1, 1, start);
    printf("%d\n", ans);
    return 0;
}
