#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
int dis[405][405];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void input() { scanf("%d%d%d%d", &n, &m, &x, &y); }

void process() {
    memset(dis, -1, sizeof(dis));
    dis[x][y] = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dis[nx][ny] == -1) {
                dis[nx][ny] = dis[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void output() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%d ", dis[i][j]);
        printf("\n");
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
