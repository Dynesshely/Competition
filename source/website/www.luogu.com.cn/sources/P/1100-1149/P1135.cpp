#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int k[210];
int dist[210];
int q[210], head, tail;

void input() {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &k[i]);
}

void process() {
    memset(dist, -1, sizeof(dist));
    dist[a] = 0;
    head = tail = 0;
    q[tail++]   = a;
    while (head < tail) {
        int u  = q[head++];
        int up = u + k[u];
        if (up <= n && dist[up] == -1) {
            dist[up]  = dist[u] + 1;
            q[tail++] = up;
        }
        int dn = u - k[u];
        if (dn >= 1 && dist[dn] == -1) {
            dist[dn]  = dist[u] + 1;
            q[tail++] = dn;
        }
    }
}

void output() { printf("%d\n", dist[b]); }

int main() {
    input();
    process();
    output();
    return 0;
}
