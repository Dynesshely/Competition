#include <bits/stdc++.h>
using namespace std;

const int N    = 1005;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int  n, m;
char g[N][N];
int  comp[N][N];
int  compSz[N * N];
int  compCnt;

void bfs(int sx, int sy) {
    compCnt++;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    comp[sx][sy] = compCnt;
    int cnt      = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        cnt++;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 1 || nx > n || ny < 1 || ny > n)
                continue;
            if (comp[nx][ny])
                continue;
            if (g[x][y] == g[nx][ny])
                continue;
            comp[nx][ny] = compCnt;
            q.push({nx, ny});
        }
    }
    compSz[compCnt] = cnt;
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", g[i] + 1);
}

void process() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!comp[i][j])
                bfs(i, j);
}

void output() {
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", compSz[comp[x][y]]);
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
