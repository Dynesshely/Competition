#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int  n, m, s, t, fa[10010];
Edge edges[20010];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a != b)
        fa[a] = b;
}

void input() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
}

int process() {
    sort(edges, edges + m, [](const Edge &a, const Edge &b) { return a.w < b.w; });
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 0; i < m; i++) {
        unite(edges[i].u, edges[i].v);
        if (find(s) == find(t))
            return edges[i].w;
    }
    return -1;
}

void output() { printf("%d\n", process()); }

int main() {
    input();
    output();
    return 0;
}
