#include <bits/stdc++.h>
using namespace std;

const int N   = 30005;
const int INF = 0x3f3f3f3f;

int                    n, m;
vector<pair<int, int>> adj[N];
int                    rk[N];
vector<int>            byRank[11];
int                    best[11][N];
int                    limit[11][N];
int                    dist[N];
int                    stamp[N];
int                    curStamp;
long long              ans;

void multiDij(int r) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    memset(best[r], 0x3f, sizeof(best[r]));
    for (int v : byRank[r]) {
        best[r][v] = 0;
        pq.push({0, v});
    }
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d != best[r][v])
            continue;
        for (auto [to, w] : adj[v]) {
            if (best[r][to] > d + w) {
                best[r][to] = d + w;
                pq.push({best[r][to], to});
            }
        }
    }
}

void dijFrom(int s) {
    int                                                                             k = rk[s];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    curStamp++;
    dist[s]  = 0;
    stamp[s] = curStamp;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (stamp[v] != curStamp || dist[v] != d)
            continue;
        if (d >= limit[k][v])
            continue;
        ans++;
        for (auto [to, w] : adj[v]) {
            int nd = d + w;
            if (stamp[to] != curStamp || nd < dist[to]) {
                dist[to]  = nd;
                stamp[to] = curStamp;
                pq.push({nd, to});
            }
        }
    }
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &rk[i]);
        byRank[rk[i]].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
}

void process() {
    memset(best, 0x3f, sizeof(best));
    for (int r = 1; r <= 10; r++)
        if (!byRank[r].empty())
            multiDij(r);

    for (int v = 1; v <= n; v++)
        limit[10][v] = INF;
    for (int r = 9; r >= 1; r--)
        for (int v = 1; v <= n; v++)
            limit[r][v] = min(limit[r + 1][v], best[r + 1][v]);

    int maxRank = 0;
    for (int r = 10; r >= 1; r--)
        if (!byRank[r].empty()) {
            maxRank = r;
            break;
        }

    ans = 0;
    for (int r = 1; r <= 10; r++) {
        if (r == maxRank) {
            ans += (long long)byRank[r].size() * n;
            continue;
        }
        for (int s : byRank[r])
            dijFrom(s);
    }
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
