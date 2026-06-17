#include <bits/stdc++.h>
using namespace std;

const int MOD  = 100003;
const int MAXN = 1000005;
const int MAXM = 4000005;

int n, m;
int head[MAXN], to[MAXM], nxt[MAXM], edgeCnt;
int dist[MAXN], cnt[MAXN];
int q[MAXN], ql, qr;

void addEdge(int u, int v) {
    to[edgeCnt]  = v;
    nxt[edgeCnt] = head[u];
    head[u]      = edgeCnt++;
}

void input() {
    (void)scanf("%d%d", &n, &m);
    fill(head, head + n + 1, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        (void)scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
}

void process() {
    fill(dist, dist + n + 1, -1);
    ql = qr = 0;
    dist[1] = 0;
    cnt[1]  = 1;
    q[qr++] = 1;
    while (ql < qr) {
        int u = q[ql++];
        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                cnt[v]  = cnt[u];
                q[qr++] = v;
            } else if (dist[v] == dist[u] + 1) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
            }
        }
    }
}

void output() {
    for (int i = 1; i <= n; i++)
        printf("%d\n", cnt[i] % MOD);
}

int main() {
    input();
    process();
    output();
    return 0;
}
