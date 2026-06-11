#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
};

int find(vector<int> &fa, int x) { return fa[x] == x ? x : fa[x] = find(fa, fa[x]); }

int main() {
    int n, w;
    scanf("%d%d", &n, &w);
    vector<edge> edges;
    edges.reserve(w);
    for (int i = 0; i < w; ++i) {
        int u, v, wgt;
        scanf("%d%d%d", &u, &v, &wgt);
        edge ne = {u, v, wgt};
        auto it = edges.begin();
        while (it != edges.end() && it->w < wgt)
            ++it;
        edges.insert(it, ne);
        vector<int> fa(n + 1);
        for (int j = 1; j <= n; ++j)
            fa[j] = j;
        int cnt = 0, sum = 0;
        for (const auto &e : edges) {
            int fu = find(fa, e.u), fv = find(fa, e.v);
            if (fu != fv) {
                fa[fu] = fv;
                sum += e.w;
                if (++cnt == n - 1)
                    break;
            }
        }
        if (cnt == n - 1)
            printf("%d\n", sum);
        else
            printf("-1\n");
    }
    return 0;
}
