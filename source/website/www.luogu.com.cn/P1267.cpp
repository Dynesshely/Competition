#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1300;

int  n, mp[5][20][40], f[MAXV][4], tot[MAXV];
int  vis[MAXV][4][MAXV];
bool e[MAXV][MAXV];
int  ans;

int readInt() {
    int  x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void addEdge(int u, int v) {
    if (!e[u][v]) {
        e[u][v]        = 1;
        f[u][++tot[u]] = v;
    }
    if (!e[v][u]) {
        e[v][u]        = 1;
        f[v][++tot[v]] = u;
    }
}

int dp(int u, int ll, int rr) {
    int fa = 1;
    while (f[u][fa] != rr)
        ++fa;
    if (vis[u][fa][ll])
        return vis[u][fa][ll];
    int l, r;
    if (ll <= rr)
        l = ll, r = rr - 1;
    else
        l = rr + 1, r = ll;
    int lson = 0, rson = 0;
    for (int k = 1; k <= 3; ++k) {
        if (k != fa && l <= f[u][k] && f[u][k] <= r) {
            if (f[u][k] < u)
                lson = max(lson, dp(f[u][k], l, u));
            else
                rson = max(rson, dp(f[u][k], r, u));
        }
    }
    vis[u][fa][ll] = lson + rson + 1;
    return vis[u][fa][ll];
}

void input() {
    n = readInt();
    for (int k = 1; k <= 4; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= i * 2 - 1; ++j)
                mp[k][i][j] = readInt();
}

void process() {
    for (int k = 1; k <= 4; ++k)
        for (int i = 2; i < n; ++i)
            for (int j = 2; j < i * 2 - 1; ++j) {
                addEdge(mp[k][i][j], mp[k][i][j - 1]);
                addEdge(mp[k][i][j], mp[k][i][j + 1]);
                if (j & 1)
                    addEdge(mp[k][i][j], mp[k][i + 1][j + 1]);
                else
                    addEdge(mp[k][i][j], mp[k][i - 1][j - 1]);
            }
    for (int k = 1; k <= 4; ++k)
        for (int i = 2; i <= n * 2 - 1; i += 2) {
            addEdge(mp[k][n][i], mp[k][n][i - 1]);
            addEdge(mp[k][n][i], mp[k][n][i + 1]);
            addEdge(mp[k][n][i], mp[k][n - 1][i - 1]);
        }
    for (int i = 1; i <= n * 2 - 1; ++i) {
        addEdge(mp[1][n][i], mp[4][n - i / 2][1]);
        addEdge(mp[2][n][i], mp[4][i / 2 + 1][(i / 2 + 1) * 2 - 1]);
        addEdge(mp[3][n][i], mp[4][n][n * 2 - i]);
    }
    for (int i = 1; i <= n; ++i) {
        addEdge(mp[1][i][1], mp[3][i][i * 2 - 1]);
        addEdge(mp[2][i][1], mp[1][i][i * 2 - 1]);
        addEdge(mp[3][i][1], mp[2][i][i * 2 - 1]);
    }
    int total = 4 * n * n;
    for (int i = 1; i <= total; ++i) {
        int lson = 0, rson = 0;
        for (int j = 1; j <= 3; ++j) {
            if (f[i][j] < i)
                lson = max(lson, dp(f[i][j], 1, i));
            else
                rson = max(rson, dp(f[i][j], total, i));
        }
        ans = max(ans, lson + rson + 1);
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
