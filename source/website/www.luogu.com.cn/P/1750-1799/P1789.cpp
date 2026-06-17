#include <bits/stdc++.h>
using namespace std;

int  n, m, k, ans = 0;
bool light[110][110];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        for (int j = (x - 2 >= 1 ? x - 2 : 1); j <= (x + 2 <= n ? x + 2 : n); ++j)
            light[j][y] = true;
        for (int j = (y - 2 >= 1 ? y - 2 : 1); j <= (y + 2 <= n ? y + 2 : n); ++j)
            light[x][j] = true;
        light[x - 1][y - 1] = true;
        light[x - 1][y + 1] = true;
        light[x + 1][y - 1] = true;
        light[x + 1][y + 1] = true;
    }
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        for (int o = (x - 2 >= 1 ? x - 2 : 1); o <= (x + 2 <= n ? x + 2 : n); ++o)
            for (int j = (y - 2 >= 1 ? y - 2 : 1); j <= (y + 2 <= n ? y + 2 : n); ++j)
                light[o][j] = true;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (!light[i][j])
                ++ans;
    printf("%d\n", ans);
    return 0;
}