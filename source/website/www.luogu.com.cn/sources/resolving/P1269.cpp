#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20005;

struct Edge {
    int to, w;
};

vector<Edge> adj[MAXN];
int          n, S, ans;

void dfs(int u, int fa, int dist) {
    for (auto &e : adj[u]) {
        if (e.to == fa)
            continue;
        if (dist + e.w >= S) {
            ans++;
            dfs(e.to, u, e.w);
        } else
            dfs(e.to, u, dist + e.w);
    }
}

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int v, w;
            scanf("%d%d", &v, &w);
            adj[i].push_back({v, w});
        }
    }
    scanf("%d", &S);
}

bool process() {
    for (int i = 1; i <= n; i++)
        for (auto &e : adj[i])
            if (e.w >= S)
                return false;
    dfs(1, 0, 0);
    return true;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    if (!process())
        printf("No solution.\n");
    else
        output();
    return 0;
}
