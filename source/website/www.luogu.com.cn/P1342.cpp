#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int         MAXN = 1000005;
const int         MAXM = 1000005;
const ll          INF  = 0x3f3f3f3f3f3f3f3fLL;

struct Edge {
    int to, w, nxt;
};

Edge ef[MAXM], er[MAXM];
int  hf[MAXN], hr[MAXN], cf, cr;
int  n, m;
ll   df[MAXN], dr[MAXN];

void addEdge(int u, int v, int w) {
    ef[++cf] = {v, w, hf[u]};
    hf[u]    = cf;
    er[++cr] = {u, w, hr[v]};
    hr[v]    = cr;
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
}

void dijkstra(int *head, Edge *edges, ll *dist) {
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue;
        for (int i = head[u]; i; i = edges[i].nxt) {
            int v = edges[i].to, w = edges[i].w;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void process() {
    dijkstra(hf, ef, df);
    dijkstra(hr, er, dr);
}

void output() {
    ll ans = 0;
    for (int i = 2; i <= n; i++)
        ans += df[i] + dr[i];
    printf("%lld\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
