#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, rev, cap;
};

struct Dinic {
    vector<vector<Edge>> g;
    vector<int>          level, it;

    Dinic(int n)
        : g(n)
        , level(n)
        , it(n) {}

    void addEdge(int from, int to, int cap) {
        g[from].push_back({to, (int)g[to].size(), cap});
        g[to].push_back({from, (int)g[from].size() - 1, 0});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto &e : g[v])
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
        }
        return level[t] >= 0;
    }

    int dfs(int v, int t, int f) {
        if (v == t)
            return f;
        for (int &i = it[v]; i < (int)g[v].size(); i++) {
            Edge &e = g[v][i];
            if (e.cap > 0 && level[v] + 1 == level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    long long maxFlow(int s, int t) {
        long long flow = 0;
        const int INF  = 1e9;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0)
                flow += f;
        }
        return flow;
    }
};

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n + 1), b(n + 1);
    long long   total = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        total += a[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        total += b[i];
    }

    int m;
    scanf("%d", &m);

    int   S = 0, T = n + 2 * m + 1;
    Dinic dinic(T + 1);

    for (int i = 1; i <= n; i++) {
        dinic.addEdge(S, i, a[i]);
        dinic.addEdge(i, T, b[i]);
    }

    const int INF = 1e9;

    for (int j = 0; j < m; j++) {
        int k, c1, c2;
        scanf("%d%d%d", &k, &c1, &c2);
        total += c1 + c2;

        int u = n + 1 + j;
        int v = n + m + 1 + j;

        dinic.addEdge(S, u, c1);
        dinic.addEdge(v, T, c2);

        for (int t = 0; t < k; t++) {
            int crop;
            scanf("%d", &crop);
            dinic.addEdge(u, crop, INF);
            dinic.addEdge(crop, v, INF);
        }
    }

    long long minCut = dinic.maxFlow(S, T);
    printf("%lld\n", total - minCut);

    return 0;
}
