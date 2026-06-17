#include <bits/stdc++.h>
using namespace std;

const int N = 155, M = 505;
const int INF = 0x3f3f3f3f;

int n, m, a[N][M], s[N][M], f[2][10][N][N], g[2][4], ss[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            s[i][j] = s[i - 1][j] + a[i][j];
        }

    memset(f, -0x3f, sizeof(f));
    memset(g, -0x3f, sizeof(g));
    int nw = 1, la = 0;
    g[la][0] = 0;

    for (int j = 1; j <= m + 1; j++) {
        memcpy(g[nw], g[la], sizeof(g[la]));

        for (int l = 1; l <= n; l++)
            for (int r = l + 1; r <= n; r++)
                f[nw][1][l][r] = max(g[la][0], f[la][1][l][r]) + s[r][j] - s[l - 1][j];

        for (int l = 1; l <= n; l++)
            for (int r = n, mx = -INF; r >= l; r--) {
                f[nw][2][l][r] = max(f[nw][2][l][r], mx + s[r][j] - s[l - 1][j]);
                mx             = max(mx, f[la][1][l][r]);
            }

        memset(ss, -0x3f, sizeof(ss));
        for (int l = 1; l <= n; l++)
            for (int r = l, mx = ss[l - 1]; r <= n; r++) {
                ss[r]          = max(ss[r], f[la][2][l][r]);
                mx             = max(mx, ss[r]);
                f[nw][2][l][r] = max(f[nw][2][l][r], mx + s[r][j] - s[l - 1][j]);
            }

        for (int r = n; r >= 1; r--)
            for (int l = r, mx = -INF; l >= 1; l--) {
                f[nw][3][l][r] = max(f[nw][3][l][r], mx + s[r][j] - s[l - 1][j]);
                mx             = max(mx, f[la][2][l][r]);
            }

        for (int l = 1; l <= n; l++)
            for (int r = l + 1; r <= n; r++) {
                f[nw][3][l][r] = max(f[nw][3][l][r], f[la][3][l][r] + s[r][j] - s[l - 1][j]);
                g[nw][1]       = max(g[nw][1], f[la][3][l][r]);
            }

        for (int l = 1; l <= n; l++)
            for (int r = l + 2; r <= n; r++)
                f[nw][4][l][r] = g[la][1] + s[r][j] - s[l - 1][j];

        for (int l = 1; l <= n; l++)
            for (int r = l + 2; r <= n; r++)
                f[nw][5][l][r] = max(f[la][4][l][r], f[la][5][l][r]) + a[l][j] + a[r][j];

        for (int l = 1; l <= n; l++)
            for (int r = l + 2; r <= n; r++) {
                f[nw][6][l][r] = f[la][5][l][r] + s[r][j] - s[l - 1][j];
                g[nw][2]       = max(g[nw][2], f[la][6][l][r]);
            }

        for (int l = 1; l <= n; l++)
            for (int r = l + 2; r <= n; r++)
                f[nw][7][l][r] = max(g[la][2], f[la][7][l][r]) + a[l][j] + a[r][j];

        for (int l = 1; l <= n; l++)
            for (int r = l + 2; r <= n; r++)
                f[nw][8][l][r] = max(f[la][7][l][r], f[la][8][l][r]) + s[r][j] - s[l - 1][j];

        for (int l = 1; l <= n; l++)
            for (int r = l + 2; r <= n; r++) {
                f[nw][9][l][r] = max(f[la][8][l][r], f[la][9][l][r]) + a[l][j] + a[r][j];
                g[nw][3]       = max(g[nw][3], f[la][9][l][r]);
            }

        memset(f[la], -0x3f, sizeof(f[la]));
        memset(g[la], -0x3f, sizeof(g[la]));
        nw ^= 1;
        la ^= 1;
    }

    printf("%d\n", g[la][3]);
    return 0;
}
