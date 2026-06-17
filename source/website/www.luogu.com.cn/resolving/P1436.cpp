#include <bits/stdc++.h>
using namespace std;

int n, a[9][9], s[9][9], f[9][9][9][9][16];

int sum(int x1, int y1, int x2, int y2) { return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]; }

int dfs(int x1, int y1, int x2, int y2, int k) {
    int &res = f[x1][y1][x2][y2][k];
    if (res != -1)
        return res;
    if (k == 1) {
        int t      = sum(x1, y1, x2, y2);
        return res = t * t;
    }
    res = 1e9;
    for (int r = x1; r < x2; r++)
        for (int k1 = 1; k1 < k; k1++)
            res = min(res, dfs(x1, y1, r, y2, k1) + dfs(r + 1, y1, x2, y2, k - k1));
    for (int c = y1; c < y2; c++)
        for (int k1 = 1; k1 < k; k1++)
            res = min(res, dfs(x1, y1, x2, c, k1) + dfs(x1, c + 1, x2, y2, k - k1));
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++) {
            scanf("%d", &a[i][j]);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    memset(f, -1, sizeof(f));
    printf("%d\n", dfs(1, 1, 8, 8, n));
    return 0;
}
