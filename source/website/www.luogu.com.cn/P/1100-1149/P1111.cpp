#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, t;
};

Edge e[100005];
int  fa[1005];
int  n, m;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].t);
}

void process() {
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    sort(e, e + m, [](const Edge &a, const Edge &b) { return a.t < b.t; });
}

void output() {
    int ans = 0, cnt = 0;
    for (int i = 0; i < m && cnt < n - 1; ++i) {
        int fu = find(e[i].u), fv = find(e[i].v);
        if (fu != fv) {
            fa[fu] = fv;
            ans    = e[i].t;
            ++cnt;
        }
    }
    if (cnt == n - 1)
        printf("%d\n", ans);
    else
        printf("-1\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
