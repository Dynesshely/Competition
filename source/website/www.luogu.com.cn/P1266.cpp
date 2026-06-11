#include <bits/stdc++.h>
using namespace std;

int                                  N, M, D;
vector<vector<tuple<int, int, int>>> adj;
vector<vector<double>>               dist;
vector<vector<pair<int, int>>>       prevNode;
const int                            MAXV = 500;

void input() {
    scanf("%d%d%d", &N, &M, &D);
    adj.resize(N);
    for (int i = 0; i < M; i++) {
        int A, B, V, L;
        scanf("%d%d%d%d", &A, &B, &V, &L);
        adj[A].push_back({B, V, L});
    }
}

void process() {
    dist.assign(N, vector<double>(MAXV + 1, 1e18));
    prevNode.assign(N, vector<pair<int, int>>(MAXV + 1, {-1, -1}));
    dist[0][70] = 0;
    using State = pair<int, int>;
    using Entry = pair<double, State>;
    priority_queue<Entry, vector<Entry>, greater<Entry>> pq;
    pq.push({0, {0, 70}});
    while (!pq.empty()) {
        auto [d, state] = pq.top();
        pq.pop();
        auto [u, s] = state;
        if (d > dist[u][s] + 1e-12)
            continue;
        for (auto &e : adj[u]) {
            int    v      = get<0>(e);
            int    vLimit = get<1>(e);
            int    len    = get<2>(e);
            double t;
            int    ns;
            if (vLimit > 0) {
                t  = (double)len / vLimit;
                ns = vLimit;
            } else {
                t  = (double)len / s;
                ns = s;
            }
            double nd = d + t;
            if (nd + 1e-12 < dist[v][ns]) {
                dist[v][ns]     = nd;
                prevNode[v][ns] = {u, s};
                pq.push({nd, {v, ns}});
            }
        }
    }
}

void output() {
    double best  = 1e18;
    int    bestS = -1;
    for (int s = 0; s <= MAXV; s++) {
        if (dist[D][s] < best) {
            best  = dist[D][s];
            bestS = s;
        }
    }
    vector<int> path;
    int         cur = D, curS = bestS;
    while (cur != -1) {
        path.push_back(cur);
        auto [p, ps] = prevNode[cur][curS];
        cur          = p;
        curS         = ps;
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size(); i++)
        printf("%d%c", path[i], i + 1 == (int)path.size() ? '\n' : ' ');
}

int main() {
    input();
    process();
    output();
    return 0;
}
