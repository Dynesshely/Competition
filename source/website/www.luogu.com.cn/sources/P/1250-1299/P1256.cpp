#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int                   n, m;
int                   dist[185][185];
char                  grid[185][185];
queue<pair<int, int>> q;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", grid[i] + 1);
}

void process() {
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (grid[i][j] == '1') {
                dist[i][j] = 0;
                q.push({i, j});
            }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void output() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            printf("%d%c", dist[i][j], j == m ? '\n' : ' ');
}

int main() {
    input();
    process();
    output();
    return 0;
}
