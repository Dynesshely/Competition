#include <bits/stdc++.h>
using namespace std;

struct Edge { int to, w; };
vector<Edge> g[305];
int n, s, dis[305], pre[305], diam[305], dlen[305], branch[305], dc;
int leftMx[305], rightMx[305];
bool onDiam[305];

void dfs1(int u, int fa) {
    for (auto &e : g[u]) {
        if (e.to == fa) continue;
        dis[e.to] = dis[u] + e.w; pre[e.to] = u; dfs1(e.to, u);
    }
}

void dfs2(int u, int fa, int &mx) {
    mx = max(mx, dis[u]);
    for (auto &e : g[u]) {
        if (e.to == fa || onDiam[e.to]) continue;
        dis[e.to] = dis[u] + e.w; dfs2(e.to, u, mx);
    }
}

int rangeMx(int l, int r) {
    int mx = 0;
    for (int k = l; k <= r; ++k) mx = max(mx, branch[k]);
    return mx;
}

int main() {
    scanf("%d%d", &n, &s);
    for (int i = 1; i < n; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w}); g[v].push_back({u, w});
    }
    dis[1] = 0; dfs1(1, 0);
    int a = 1; for (int i = 2; i <= n; ++i) if (dis[i] > dis[a]) a = i;
    dis[a] = 0; pre[a] = 0; dfs1(a, 0);
    int b = 1; for (int i = 2; i <= n; ++i) if (dis[i] > dis[b]) b = i;
    dc = 0;
    for (int u = b; u; u = pre[u]) diam[dc++] = u;
    reverse(diam, diam + dc);
    for (int i = 0; i < dc; ++i) { dlen[i] = dis[diam[i]]; onDiam[diam[i]] = true; }
    for (int i = 0; i < dc; ++i) { dis[diam[i]] = 0; int mx = 0; dfs2(diam[i], 0, mx); branch[i] = mx; }
    leftMx[0] = -0x7fffffff;
    for (int i = 1; i < dc; ++i) leftMx[i] = max(leftMx[i - 1], branch[i - 1] - dlen[i - 1]);
    rightMx[dc - 1] = -0x7fffffff;
    for (int i = dc - 2; i >= 0; --i) rightMx[i] = max(rightMx[i + 1], branch[i + 1] + dlen[i + 1]);
    int ans = 0x7fffffff;
    for (int l = 0; l < dc; ++l) {
        for (int r = l; r < dc && dlen[r] - dlen[l] <= s; ++r) {
            int ecc = max(dlen[l], dlen[dc - 1] - dlen[r]);
            ecc = max(ecc, rangeMx(l, r));
            if (l > 0) ecc = max(ecc, dlen[l] + leftMx[l]);
            if (r < dc - 1) ecc = max(ecc, rightMx[r] - dlen[r]);
            ans = min(ans, ecc);
        }
    }
    printf("%d\n", ans);
    return 0;
}
