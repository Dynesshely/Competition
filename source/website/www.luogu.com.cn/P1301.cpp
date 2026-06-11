#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105][105];
int dist[105][105][8];
int dc[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dr[8] = {0, 0, -1, 1, -1, -1, 1, 1};
struct State {
    int x, y, d;
};

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void process() {
    memset(dist, -1, sizeof(dist));
    queue<State> q;
    for (int d = 0; d < 8; d++) {
        int nx = 1 + a[0][0] * dc[d];
        int ny = 1 + a[0][0] * dr[d];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
            dist[ny - 1][nx - 1][d] = 1;
            q.push({nx, ny, d});
        }
    }
    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        int x = cur.x, y = cur.y, pd = cur.d;
        int X = a[y - 1][x - 1];
        for (int d = 0; d < 8; d++) {
            if (d == pd)
                continue;
            int nx = x + X * dc[d];
            int ny = y + X * dr[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[ny - 1][nx - 1][d] == -1) {
                dist[ny - 1][nx - 1][d] = dist[y - 1][x - 1][pd] + 1;
                q.push({nx, ny, d});
            }
        }
    }
}

void output() {
    int ans = -1;
    for (int d = 0; d < 8; d++)
        if (dist[m - 1][n - 1][d] != -1 && (ans == -1 || dist[m - 1][n - 1][d] < ans))
            ans = dist[m - 1][n - 1][d];
    if (ans == -1)
        printf("NEVER\n");
    else
        printf("%d\n", ans);
}

int main() {
    input();
    if (n == 1 && m == 1) {
        printf("0\n");
        return 0;
    }
    process();
    output();
    return 0;
}
