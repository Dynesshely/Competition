#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, rev, cap;
};

class Dinic {
  public:
    int                  n;
    vector<vector<Edge>> g;
    vector<int>          level, it;

    Dinic(int n_)
        : n(n_)
        , g(n_)
        , level(n_)
        , it(n_) {}

    void addEdge(int u, int v, int cap) {
        g[u].push_back({v, (int)g[v].size(), cap});
        g[v].push_back({u, (int)g[u].size() - 1, 0});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &e : g[u]) {
                if (e.cap > 0 && level[e.v] < 0) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] >= 0;
    }

    int dfs(int u, int t, int f) {
        if (u == t)
            return f;
        for (int &i = it[u]; i < (int)g[u].size(); ++i) {
            Edge &e = g[u][i];
            if (e.cap > 0 && level[u] < level[e.v]) {
                int ret = dfs(e.v, t, min(f, e.cap));
                if (ret > 0) {
                    e.cap -= ret;
                    g[e.v][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            int f;
            while ((f = dfs(s, t, 1e9)) > 0)
                flow += f;
        }
        return flow;
    }
};

int n, p, q, ans;

void input() { scanf("%d%d%d", &n, &p, &q); }

void process() {
    int   S           = 0;
    int   roomOff     = 1;
    int   guestInOff  = roomOff + p;
    int   guestOutOff = guestInOff + n;
    int   dishOff     = guestOutOff + n;
    int   T           = dishOff + q;
    Dinic dinic(T + 1);

    for (int i = 0; i < p; ++i)
        dinic.addEdge(S, roomOff + i, 1);

    for (int i = 0; i < n; ++i)
        dinic.addEdge(guestInOff + i, guestOutOff + i, 1);

    for (int i = 0; i < q; ++i)
        dinic.addEdge(dishOff + i, T, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            int x;
            scanf("%d", &x);
            if (x)
                dinic.addEdge(roomOff + j, guestInOff + i, 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q; ++j) {
            int x;
            scanf("%d", &x);
            if (x)
                dinic.addEdge(guestOutOff + i, dishOff + j, 1);
        }
    }

    ans = dinic.maxFlow(S, T);
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
