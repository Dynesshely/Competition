#include <bits/stdc++.h>
using namespace std;

const int       MAXN = 205;
const long long INF  = 1LL << 60;

struct Edge {
    int       v, rev;
    long long cap;
};

vector<Edge> g[MAXN];
int          level[MAXN], it[MAXN];
int          n, m, x;

void addEdge(int u, int v, long long c) {
    g[u].push_back({v, (int)g[v].size(), c});
    g[v].push_back({u, (int)g[u].size() - 1, 0});
}

bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &e : g[u])
            if (e.cap > 0 && level[e.v] < 0) {
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
    }
    return level[t] >= 0;
}

long long dfs(int u, int t, long long f) {
    if (u == t)
        return f;
    for (int &i = it[u]; i < (int)g[u].size(); i++) {
        Edge &e = g[u][i];
        if (e.cap > 0 && level[u] < level[e.v]) {
            long long d = dfs(e.v, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                g[e.v][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

long long maxFlow(int s, int t) {
    long long flow = 0;
    while (bfs(s, t)) {
        memset(it, 0, sizeof(it));
        long long f;
        while ((f = dfs(s, t, INF)) > 0)
            flow += f;
    }
    return flow;
}

void input() { scanf("%d%d%d", &n, &m, &x); }

void process() {
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addEdge(a, b, c);
    }
    long long perBatch = maxFlow(1, n);
    if (perBatch == 0)
        printf("Orz Ni Jinan Saint Cow!\n");
    else
        printf("%lld %lld\n", perBatch, (x + perBatch - 1) / perBatch);
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
