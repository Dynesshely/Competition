#include <bits/stdc++.h>
using namespace std;

int                    m, n, sx, sy, ex, ey;
int                    a[15][15];
bool                   via[15][15];
int                    dx[] = {-1, 0, 0, 1};
int                    dy[] = {0, -1, 1, 0};
vector<pair<int, int>> path;
bool                   hasPath;

void dfs(int x, int y) {
    if (x == ex && y == ey) {
        hasPath = true;
        for (int i = 0; i < (int)path.size(); i++) {
            if (i)
                printf("->");
            printf("(%d,%d)", path[i].first, path[i].second);
        }
        printf("\n");
        return;
    }
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && a[nx][ny] && !via[nx][ny]) {
            via[nx][ny] = true;
            path.push_back({nx, ny});
            dfs(nx, ny);
            path.pop_back();
            via[nx][ny] = false;
        }
    }
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    path.push_back({sx, sy});
    via[sx][sy] = true;
    dfs(sx, sy);
    if (!hasPath)
        printf("-1\n");
    return 0;
}
