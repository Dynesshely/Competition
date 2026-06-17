#include <bits/stdc++.h>
using namespace std;

const int maxN = 6005;

int  n, r[maxN], dp[maxN][2], head[maxN], edgeCnt, root;
bool notRoot[maxN];

struct Edge {
    int to, nxt;
} e[maxN];

void addEdge(int u, int v) {
    e[++edgeCnt] = {v, head[u]};
    head[u]      = edgeCnt;
}

void dfs(int u) {
    dp[u][1] = r[u];
    dp[u][0] = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        dfs(v);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
}

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &r[i]);
    for (int i = 1; i < n; ++i) {
        int l, k;
        scanf("%d%d", &l, &k);
        addEdge(k, l);
        notRoot[l] = true;
    }
}

void process() {
    root = 0;
    for (int i = 1; i <= n; ++i)
        if (!notRoot[i]) {
            root = i;
            break;
        }
    dfs(root);
}

void output() { printf("%d\n", max(dp[root][0], dp[root][1])); }

int main() {
    input();
    process();
    output();
    return 0;
}
