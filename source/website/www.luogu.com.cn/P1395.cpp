#include <bits/stdc++.h>
using namespace std;

int         n, idx, minSum;
vector<int> g[50001];
int         sz[50001], f[50001];

void dfs1(int u, int p, int d) {
    sz[u] = 1;
    f[1] += d;
    for (int v : g[u])
        if (v != p) {
            dfs1(v, u, d + 1);
            sz[u] += sz[v];
        }
}

void dfs2(int u, int p) {
    for (int v : g[u])
        if (v != p) {
            f[v] = f[u] + n - 2 * sz[v];
            if (f[v] < minSum || (f[v] == minSum && v < idx)) {
                minSum = f[v];
                idx    = v;
            }
            dfs2(v, u);
        }
}

void input() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

void process() {
    dfs1(1, 0, 0);
    idx    = 1;
    minSum = f[1];
    dfs2(1, 0);
}

void output() { printf("%d %d\n", idx, minSum); }

int main() {
    input();
    process();
    output();
    return 0;
}
