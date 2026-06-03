#include <bits/stdc++.h>
using namespace std;

const int       N    = 200010;
const long long INF  = 0x3f3f3f3f3f3f3f3fll;
const long long BIG  = 1e9;
const long long MAXF = 1e18;

struct Edge {
    int       to;
    long long cap, fee;
    int       rev;
};

vector<Edge> g[N];
int          n, s, t, cur[N];
long long    dis[N], totCost;
bool         via[N];

void link(int u, int v, long long w, long long ct) {
    g[u].push_back({v, w, ct, (int)g[v].size()});
    g[v].push_back({u, 0, -ct, (int)g[u].size() - 1});
}

bool bfs() {
    memset(dis, 0x3f, sizeof dis);
    memset(via, 0, sizeof via);
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    via[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        via[u] = false;
        for (auto &e : g[u])
            if (e.cap && dis[e.to] > dis[u] + e.fee) {
                dis[e.to] = dis[u] + e.fee;
                if (!via[e.to]) {
                    q.push(e.to);
                    via[e.to] = true;
                }
            }
    }
    return dis[t] != INF;
}

long long augment(int u, long long lim) {
    if (u == t)
        return lim;
    via[u] = true;
    for (int &i = cur[u]; i < (int)g[u].size(); ++i) {
        Edge &e = g[u][i];
        if (!via[e.to] && dis[u] + e.fee == dis[e.to] && e.cap) {
            long long f = augment(e.to, min(lim, e.cap));
            if (f) {
                e.cap -= f;
                g[e.to][e.rev].cap += f;
                totCost += f * e.fee;
                via[u] = false;
                return f;
            }
        }
    }
    via[u] = false;
    return 0;
}

void solve() {
    while (bfs()) {
        memset(cur, 0, sizeof cur);
        long long f;
        while ((f = augment(s, MAXF)))
            ;
    }
}

int main() {
    int c1, c2, k1, k2, base;
    scanf("%d%d%d%d%d%d", &n, &c1, &c2, &k1, &k2, &base);
    s = 0;
    t = 2 * n + 1;
    for (int i = 1; i <= n; ++i) {
        link(s, i + n, BIG, base);
        if (i + c1 <= n)
            link(i, i + n + c1, BIG, k1);
        if (i + c2 <= n)
            link(i, i + n + c2, BIG, k2);
        if (i < n)
            link(i, i + 1, BIG, 0);
    }
    solve();
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x);
        link(s, i, x, 0);
        link(i + n, t, x, 0);
    }
    solve();
    printf("%lld\n", totCost);
    return 0;
}
