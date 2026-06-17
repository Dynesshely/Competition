#include <bits/stdc++.h>
using namespace std;

const int              INF = 0x3f3f3f3f;
int                    n, m, s, t, dist[2505];
vector<pair<int, int>> g[2505];

void input() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}

void process() {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d != dist[u])
            continue;
        for (auto &e : g[u]) {
            int v = e.first, w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void output() { printf("%d\n", dist[t]); }

int main() {
    input();
    process();
    output();
    return 0;
}
