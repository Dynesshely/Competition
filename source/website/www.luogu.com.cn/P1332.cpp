#include <bits/stdc++.h>
using namespace std;

int                   n, m, a, b;
int                   dx[] = {0, 0, 1, -1};
int                   dy[] = {1, -1, 0, 0};
int                   dist[505][505];
queue<pair<int, int>> q;

void input() {
    scanf("%d%d%d%d", &n, &m, &a, &b);
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < a; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        dist[x][y] = 0;
        q.push({x, y});
    }
}

void process() {
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (dist[nx][ny] != -1)
                continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

void output() {
    for (int i = 0; i < b; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", dist[x][y]);
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
