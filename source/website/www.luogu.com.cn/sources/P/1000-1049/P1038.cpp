#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    vector<int> C(n + 1), U(n + 1), indeg(n + 1), outdeg(n + 1);
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &C[i], &U[i]);
        if (C[i] == 0) C[i] -= U[i];
    }
    for (int i = 0; i < p; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        ++indeg[v];
        ++outdeg[u];
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (C[u] > 0)
            for (auto [v, w] : g[u]) {
                C[v] += w * C[u];
                if (--indeg[v] == 0) {
                    C[v] = max(C[v], 0);
                    q.push(v);
                }
            }
        else
            for (auto [v, w] : g[u])
                if (--indeg[v] == 0) q.push(v);
    }
    bool output = false;
    for (int i = 1; i <= n; ++i)
        if (outdeg[i] == 0 && C[i] > 0) {
            printf("%d %d\n", i, C[i]);
            output = true;
        }
    if (!output) printf("NULL\n");
    return 0;
}
