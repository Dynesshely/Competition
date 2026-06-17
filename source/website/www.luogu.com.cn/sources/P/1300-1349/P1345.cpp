#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, rev, cap;
};

const int            INF = 1e9;
int                  n, m, c1, c2;
vector<vector<Edge>> g;

void addEdge(int u, int v, int cap) {
    g[u].push_back({v, (int)g[v].size(), cap});
    g[v].push_back({u, (int)g[u].size() - 1, 0});
}

int dinic(int s, int t) {
    int         flow = 0;
    vector<int> level, iter;
    while (true) {
        level.assign(g.size(), -1);
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
        if (level[t] < 0)
            break;
        iter.assign(g.size(), 0);
        function<int(int, int)> dfs = [&](int u, int f) -> int {
            if (u == t)
                return f;
            for (int &i = iter[u]; i < (int)g[u].size(); i++) {
                Edge &e = g[u][i];
                if (e.cap > 0 && level[e.v] == level[u] + 1) {
                    int d = dfs(e.v, min(f, e.cap));
                    if (d > 0) {
                        e.cap -= d;
                        g[e.v][e.rev].cap += d;
                        return d;
                    }
                }
            }
            return 0;
        };
        int f;
        while ((f = dfs(s, INF)) > 0)
            flow += f;
    }
    return flow;
}

void input() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    c1--;
    c2--;
    int N = 2 * n;
    g.resize(N);
    for (int i = 0; i < n; i++) {
        if (i == c1 || i == c2)
            addEdge(i, i + n, INF);
        else
            addEdge(i, i + n, 1);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        addEdge(u + n, v, INF);
        addEdge(v + n, u, INF);
    }
}

void process() {}

void output() { printf("%d\n", dinic(c1 + n, c2)); }

int main() {
    input();
    process();
    output();
    return 0;
}
