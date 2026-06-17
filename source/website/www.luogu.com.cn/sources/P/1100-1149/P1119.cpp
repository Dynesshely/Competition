#include <bits/stdc++.h>
using namespace std;

const int INF  = 0x3f3f3f3f;
const int MAXN = 205;

int n, m, q;
int t[MAXN];
int dist[MAXN][MAXN];
int queries[50005][3];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        dist[u][v] = dist[v][u] = w;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
        scanf("%d%d%d", &queries[i][0], &queries[i][1], &queries[i][2]);
}

void process() {
    int k = 0;
    for (int i = 0; i < q; i++) {
        int x = queries[i][0], y = queries[i][1], curT = queries[i][2];
        while (k < n && t[k] <= curT) {
            for (int u = 0; u < n; u++) {
                if (dist[u][k] == INF)
                    continue;
                for (int v = 0; v < n; v++) {
                    if (dist[k][v] == INF)
                        continue;
                    if (dist[u][k] + dist[k][v] < dist[u][v]) {
                        dist[u][v] = dist[u][k] + dist[k][v];
                    }
                }
            }
            k++;
        }
        if (t[x] > curT || t[y] > curT || dist[x][y] == INF) {
            queries[i][0] = -1;
        } else {
            queries[i][0] = dist[x][y];
        }
    }
}

void output() {
    for (int i = 0; i < q; i++)
        printf("%d\n", queries[i][0]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
