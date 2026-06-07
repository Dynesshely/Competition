#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int x, y, w;
};

bool cmp(const Edge &a, const Edge &b) { return a.w < b.w; }

int parent[1005], rnk[1005];

int find(int u) {
    while (parent[u] != u) {
        parent[u] = parent[parent[u]];
        u         = parent[u];
    }
    return u;
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (rnk[u] < rnk[v])
        parent[u] = v;
    else if (rnk[u] > rnk[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rnk[u]++;
    }
}

int  n, m, k;
Edge edges[10005];

void input() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &edges[i].x, &edges[i].y, &edges[i].w);
}

void process() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rnk[i]    = 0;
    }
    sort(edges, edges + m, cmp);
    int cost = 0, cnt = n;
    for (int i = 0; i < m && cnt > k; i++) {
        if (find(edges[i].x) != find(edges[i].y)) {
            unite(edges[i].x, edges[i].y);
            cost += edges[i].w;
            cnt--;
        }
    }
    if (cnt != k)
        printf("No Answer\n");
    else
        printf("%d\n", cost);
}

int main() {
    input();
    process();
    return 0;
}
