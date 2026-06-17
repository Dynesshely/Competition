#include <bits/stdc++.h>
using namespace std;

int n;
int grid[101][101];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        grid[x][y]++;
    }
}

void process() {
    int ans = 0;
    for (int xl = 1; xl <= 100; xl++) {
        int strip[101] = {0};
        for (int xr = xl; xr <= 100; xr++) {
            for (int y = 1; y <= 100; y++)
                strip[y] += grid[xr][y];
            if (xr == xl)
                continue;
            int side[101] = {0};
            for (int y = 1; y <= 100; y++)
                side[y] = grid[xl][y] + grid[xr][y];
            int f[101] = {0};
            for (int y = 1; y <= 100; y++)
                f[y] = f[y - 1] + side[y];
            int g[101] = {0};
            for (int y = 1; y <= 100; y++)
                g[y] = strip[y] + f[y - 1];
            int sufMax[102] = {0};
            for (int y = 100; y >= 1; y--)
                sufMax[y] = max(g[y], sufMax[y + 1]);
            for (int yb = 1; yb <= 99; yb++) {
                int cur = strip[yb] - f[yb] + sufMax[yb + 1];
                if (cur > ans)
                    ans = cur;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
