#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int         n, m;
vector<pii> g[1005];
int         dist[1005], parent[1005];
int         ans;

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue;
        for (auto [v, w] : g[u])
            if (dist[u] + w < dist[v]) {
                dist[v]   = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
    }
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, v;
        scanf("%d%d%d", &a, &b, &v);
        g[a].push_back({b, v});
        g[b].push_back({a, v});
    }
}

void process() {
    dijkstra(1);
    vector<int> path;
    int         cur = n;
    while (cur != 1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    ans = 0;
    for (int i = 0; i + 1 < (int)path.size(); i++) {
        int u = path[i], v = path[i + 1];
        int wu = -1, wv = -1;
        for (auto &e : g[u])
            if (e.first == v) {
                wu       = e.second;
                e.second = 0x3f3f3f3f;
                break;
            }
        for (auto &e : g[v])
            if (e.first == u) {
                wv       = e.second;
                e.second = 0x3f3f3f3f;
                break;
            }
        dijkstra(1);
        if (dist[n] > ans)
            ans = dist[n];
        for (auto &e : g[u])
            if (e.first == v) {
                e.second = wu;
                break;
            }
        for (auto &e : g[v])
            if (e.first == u) {
                e.second = wv;
                break;
            }
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
