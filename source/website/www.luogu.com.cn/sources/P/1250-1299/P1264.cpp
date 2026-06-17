#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, rev, cap;
};

class Dinic {
  public:
    vector<vector<Edge>> g;
    vector<int>          level, it;
    int                  n;

    Dinic(int n)
        : n(n)
        , g(n)
        , level(n)
        , it(n) {}

    void addEdge(int u, int v, int cap) {
        g[u].push_back({v, (int)g[v].size(), cap});
        g[v].push_back({u, (int)g[u].size() - 1, 0});
    }

    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
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
    }

    int dfs(int u, int t, int f) {
        if (u == t)
            return f;
        for (int &i = it[u]; i < (int)g[u].size(); i++) {
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
        while (true) {
            bfs(s);
            if (level[t] < 0)
                break;
            fill(it.begin(), it.end(), 0);
            int f;
            while ((f = dfs(s, t, 1e9)) > 0)
                flow += f;
        }
        return flow;
    }
};

int                 n;
vector<int>         w, d;
vector<vector<int>> a;
vector<int>         ans;

void input() {
    scanf("%d", &n);
    w.resize(n);
    d.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &w[i], &d[i]);
    a.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void process() {
    for (int x = 0; x < n; x++) {
        int maxWins = w[x];
        for (int j = 0; j < n; j++)
            if (j != x)
                maxWins += a[x][j];

        bool ok = true;
        for (int y = 0; y < n && ok; y++)
            if (y != x && w[y] > maxWins)
                ok = false;
        if (!ok)
            continue;

        vector<pair<int, int>> games;
        for (int i = 0; i < n; i++) {
            if (i == x)
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j == x)
                    continue;
                if (a[i][j] > 0)
                    games.push_back({i, j});
            }
        }

        int         g = games.size();
        vector<int> teamIdx(n, -1);
        int         teamCnt = 0;
        for (int y = 0; y < n; y++)
            if (y != x)
                teamIdx[y] = teamCnt++;

        int   S = 0, T = 1 + g + teamCnt;
        Dinic dinic(T + 1);

        int totalRem = 0;
        for (int i = 0; i < g; i++) {
            int gameNode = 1 + i;
            int u = games[i].first, v = games[i].second;
            int cap = a[u][v];
            totalRem += cap;
            dinic.addEdge(S, gameNode, cap);
            dinic.addEdge(gameNode, 1 + g + teamIdx[u], cap);
            dinic.addEdge(gameNode, 1 + g + teamIdx[v], cap);
        }

        for (int y = 0; y < n; y++) {
            if (y != x) {
                int limit = maxWins - w[y];
                dinic.addEdge(1 + g + teamIdx[y], T, limit);
            }
        }

        if (dinic.maxFlow(S, T) == totalRem)
            ans.push_back(x + 1);
    }
}

void output() {
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
