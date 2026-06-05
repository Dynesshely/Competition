#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

int         n, m;
vector<int> g[MAXN];
int         inDeg[MAXN], dp[MAXN];
int         q[MAXN], head, tail;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        inDeg[y]++;
    }
}

void process() {
    head = 0, tail = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        if (inDeg[i] == 0) {
            q[tail++] = i;
        }
    }
    while (head < tail) {
        int u = q[head++];
        for (int v : g[u]) {
            if (dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
            }
            if (--inDeg[v] == 0) {
                q[tail++] = v;
            }
        }
    }
}

void output() {
    for (int i = 1; i <= n; i++) {
        printf("%d\n", dp[i]);
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
