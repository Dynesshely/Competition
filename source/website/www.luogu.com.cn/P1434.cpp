#include <bits/stdc++.h>
using namespace std;

const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int       r, c, h[105][105], dp[105][105];

int dfs(int x, int y) {
    if (dp[x][y])
        return dp[x][y];
    int best = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && h[nx][ny] < h[x][y])
            best = max(best, dfs(nx, ny) + 1);
    }
    return dp[x][y] = best;
}

void input() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &h[i][j]);
}

void process() {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (!dp[i][j])
                dfs(i, j);
}

void output() {
    int ans = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (dp[i][j] > ans)
                ans = dp[i][j];
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
