#include <bits/stdc++.h>
using namespace std;

int         n, m;
int         h[305];
vector<int> g[305];
bool        via[305];

void dfs(int u) {
    via[u] = true;
    for (int v : g[u])
        if (!via[v])
            dfs(v);
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (h[u] > h[v])
            g[u].push_back(v);
        else if (h[v] > h[u])
            g[v].push_back(u);
    }
}

void process() {
    for (int i = 1; i <= n; i++) {
        memset(via, 0, sizeof(via));
        dfs(i);
        bool ok = true;
        for (int j = 1; j <= n; j++)
            if (!via[j]) {
                ok = false;
                break;
            }
        if (ok) {
            printf("Oui, j'ai trouve la solution.\n%d\n", i);
            return;
        }
    }
    printf("Non\n");
}

int main() {
    input();
    process();
    return 0;
}
