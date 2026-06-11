#include <bits/stdc++.h>
using namespace std;

int                    n, a, b;
vector<pair<int, int>> adj[105];
int                    dist[105];
bool                   via[105];

void input() {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            int v;
            scanf("%d", &v);
            adj[i].push_back({v, j == 1 ? 0 : 1});
        }
    }
}

void process() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    memset(dist, 0x3f, sizeof(dist));
    dist[a] = 0;
    pq.push({0, a});
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (via[u])
            continue;
        via[u] = true;
        for (auto &e : adj[u]) {
            int v = e.first, w = e.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void output() {
    if (dist[b] == 0x3f3f3f3f)
        printf("-1\n");
    else
        printf("%d\n", dist[b]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
