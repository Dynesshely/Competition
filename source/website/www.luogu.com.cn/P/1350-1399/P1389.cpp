#include <bits/stdc++.h>
using namespace std;

const int N = 155;

int           n, hashCnt, val[N], a[N], last[N], pre1[N], pre2[N], pre3[N], f[N][N][N], g[N][N][N], ans[N];
map<int, int> hashId;

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &val[i]);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (!hashId[a[i]])
            hashId[a[i]] = ++hashCnt;
    }
}

void process() {
    for (int i = 1; i <= n; ++i) {
        pre1[i]            = last[hashId[a[i] - 1]];
        pre2[i]            = last[hashId[a[i] + 1]];
        pre3[i]            = last[hashId[a[i]]];
        last[hashId[a[i]]] = i;
    }
    memset(f, -63, sizeof(f));
    memset(g, -63, sizeof(g));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j)
            if (i + j > n)
                break;
            else
                f[i][i][j] = g[i][i][j] = val[j + 1];
        f[i][i - 1][0] = g[i][i - 1][0] = 0;
    }
    for (int len = 1; len <= n; ++len)
        for (int i = 1; i + len <= n; ++i) {
            int j = i + len;
            for (int k = 0; k <= n; ++k) {
                if (j + k > n)
                    break;
                f[i][j][k] = max(f[i][j][k], f[i][j - 1][0] + val[k + 1]);
                g[i][j][k] = max(g[i][j][k], f[i][j - 1][0] + val[k + 1]);
                int p      = pre1[j];
                while (p >= i) {
                    g[i][j][k] = max(g[i][j][k], g[i][p][k + 1] + f[p + 1][j - 1][0]);
                    f[i][j][k] = max(f[i][j][k], g[i][p][k + 1] + f[p + 1][j - 1][0]);
                    p          = pre3[p];
                }
                p = pre2[j];
                while (p >= i) {
                    f[i][j][k] = max(f[i][j][k], g[i][p][k + 1] + f[p + 1][j - 1][0]);
                    f[i][j][k] = max(f[i][j][k], f[i][p][k + 1] + f[p + 1][j - 1][0]);
                    p          = pre3[p];
                }
            }
        }
    for (int i = 1; i <= n; ++i) {
        ans[i] = ans[i - 1];
        for (int j = 0; j < i; ++j)
            ans[i] = max(ans[i], ans[j] + f[j + 1][i][0]);
    }
}

void output() { printf("%d\n", ans[n]); }

int main() {
    input();
    process();
    output();
    return 0;
}
