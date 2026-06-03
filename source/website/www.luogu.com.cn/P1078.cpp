#include <bits/stdc++.h>
using namespace std;

int n, k, m, s, t;
int c[105], reject[105][105], g[105][105], dis[105];
bool via[105];

int main() {
    scanf("%d%d%d%d%d", &n, &k, &m, &s, &t);
    for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= k; ++j) scanf("%d", &reject[i][j]);
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        if (g[u][v] == 0 || d < g[u][v]) g[u][v] = g[v][u] = d;
    }
    for (int i = 1; i <= n; ++i) dis[i] = 0x3f3f3f3f;
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dis[u]) continue;
        if (u == t) { printf("%d\n", d); return 0; }
        via[u] = true;
        for (int v = 1; v <= n; ++v) {
            if (g[u][v] == 0 || via[v]) continue;
            if (reject[c[v]][c[u]]) continue;
            if (d + g[u][v] < dis[v]) {
                dis[v] = d + g[u][v];
                pq.push({dis[v], v});
            }
        }
    }
    printf("-1\n");
    return 0;
}
