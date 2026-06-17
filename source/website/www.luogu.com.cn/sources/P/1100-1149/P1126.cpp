#include <bits/stdc++.h>
using namespace std;

const int INF  = 0x3f3f3f3f;
const int MAXN = 55;

int  n, m, g[MAXN][MAXN];
bool blk[MAXN][MAXN];
int  sx, sy, tx, ty;
char sd;
int  d[MAXN][MAXN][4];
int  dx[4] = {0, 1, 0, -1};
int  dy[4] = {1, 0, -1, 0};

int getDir(char c) {
    if (c == 'E')
        return 0;
    if (c == 'S')
        return 1;
    if (c == 'W')
        return 2;
    return 3;
}

struct Sta {
    int x, y, d;
};

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &g[i][j]);
    scanf("%d%d%d%d %c", &sx, &sy, &tx, &ty, &sd);
}

void process() {
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (g[i - 1][j - 1] || g[i - 1][j] || g[i][j - 1] || g[i][j])
                blk[i][j] = true;
    memset(d, 0x3f, sizeof(d));
    queue<Sta> q;
    int        sdir = getDir(sd);
    d[sx][sy][sdir] = 0;
    q.push({sx, sy, sdir});
    while (!q.empty()) {
        Sta c = q.front();
        q.pop();
        int x = c.x, y = c.y, dir = c.d, cd = d[x][y][dir];
        int nd = (dir + 3) % 4;
        if (d[x][y][nd] > cd + 1) {
            d[x][y][nd] = cd + 1;
            q.push({x, y, nd});
        }
        nd = (dir + 1) % 4;
        if (d[x][y][nd] > cd + 1) {
            d[x][y][nd] = cd + 1;
            q.push({x, y, nd});
        }
        for (int step = 1; step <= 3; step++) {
            int nx = x + dx[dir] * step;
            int ny = y + dy[dir] * step;
            if (nx < 1 || nx >= n || ny < 1 || ny >= m || blk[nx][ny])
                break;
            if (d[nx][ny][dir] > cd + 1) {
                d[nx][ny][dir] = cd + 1;
                q.push({nx, ny, dir});
            }
        }
    }
}

void output() {
    int ans = INF;
    for (int i = 0; i < 4; i++)
        ans = min(ans, d[tx][ty][i]);
    if (ans >= INF)
        printf("-1\n");
    else
        printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
