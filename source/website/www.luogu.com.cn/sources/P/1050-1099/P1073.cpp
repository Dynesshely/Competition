#include <bits/stdc++.h>
using namespace std;

int price[100005], minP[100005], maxP[100005];
vector<int> g[100005], rg[100005];
bool via[100005];

void dfs1(int u, int mn) {
    via[u] = true;
    if (price[u] < mn) mn = price[u];
    minP[u] = mn;
    for (int v : g[u])
        if (!via[v] || price[v] < minP[v] || mn < minP[v]) dfs1(v, mn);
}

void dfs2(int u, int mx) {
    via[u] = true;
    if (price[u] > mx) mx = price[u];
    maxP[u] = mx;
    for (int v : rg[u])
        if (!via[v] || price[v] > maxP[v] || mx > maxP[v]) dfs2(v, mx);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &price[i]);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back(y); rg[y].push_back(x);
        if (z == 2) { g[y].push_back(x); rg[x].push_back(y); }
    }
    memset(minP, 0x3f, sizeof(minP));
    memset(maxP, -1, sizeof(maxP));
    memset(via, 0, sizeof(via)); dfs1(1, price[1]);
    memset(via, 0, sizeof(via)); dfs2(n, price[n]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (maxP[i] - minP[i] > ans) ans = maxP[i] - minP[i];
    printf("%d\n", ans);
    return 0;
}
