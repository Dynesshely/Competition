#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
};

int  a, b, tot;
edge edges[125251];
int  parent[501];

int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

void input() {
    scanf("%d%d", &a, &b);
    tot = 0;
    for (int i = 1; i <= b; ++i)
        edges[tot++] = {0, i, a};
    for (int i = 1; i <= b; ++i)
        for (int j = 1; j <= b; ++j) {
            int k;
            scanf("%d", &k);
            if (j > i && k != 0)
                edges[tot++] = {i, j, k};
        }
}

void process() {
    sort(edges, edges + tot, [](const edge &x, const edge &y) { return x.w < y.w; });
    for (int i = 0; i <= b; ++i)
        parent[i] = i;
    int ans = 0, cnt = 0;
    for (int i = 0; i < tot; ++i) {
        int ru = find(edges[i].u), rv = find(edges[i].v);
        if (ru != rv) {
            parent[ru] = rv;
            ans += edges[i].w;
            ++cnt;
            if (cnt == b)
                break;
        }
    }
    printf("%d\n", ans);
}

void output() {}

int main() {
    input();
    process();
    return 0;
}
