#include <bits/stdc++.h>
using namespace std;

int    n, m, s, d;
char   grid[55][55];
int    sx, sy, ex, ey;
string tMov, dMov;
int    tLen, dLen;
int    dx[] = {0, -1, 1, 0, 0};
int    dy[] = {0, 0, 0, -1, 1};

struct Pos {
    int x, y;
};

Pos movePos(Pos p, char c) {
    int idx = c - '0';
    if (idx == 0)
        return p;
    int nx = p.x + dx[idx];
    int ny = p.y + dy[idx];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        return p;
    if (grid[nx][ny] == '1')
        return p;
    return {nx, ny};
}

void input() {
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < n; i++)
        scanf("%s", grid[i]);
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    sx--;
    sy--;
    ex--;
    ey--;
    cin >> tMov >> dMov;
    tLen = tMov.length();
    dLen = dMov.length();
}

void process() {
    const int   MAXT = 200;
    vector<Pos> tPos(MAXT + 1), dPos(MAXT + 1);
    tPos[0] = {sx, sy};
    dPos[0] = {ex, ey};
    for (int i = 0; i < MAXT; i++) {
        tPos[i + 1] = movePos(tPos[i], tMov[i % tLen]);
        dPos[i + 1] = movePos(dPos[i], dMov[i % dLen]);
    }

    const int           INF = 1e9;
    vector<vector<int>> dis(n, vector<int>(m, INF));
    dis[sx][sy] = 0;

    if (sx == ex && sy == ey) {
        printf("0\n");
        return;
    }

    int d2 = d * d;

    for (int t = 0; t < MAXT; t++) {
        vector<vector<int>> nd(n, vector<int>(m, INF));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dis[i][j] == INF)
                    continue;
                for (int dir = 0; dir < 5; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (grid[nx][ny] == '1')
                        continue;
                    int dsq = (nx - tPos[t + 1].x) * (nx - tPos[t + 1].x) + (ny - tPos[t + 1].y) * (ny - tPos[t + 1].y);
                    int nk  = (dsq <= d2) ? 0 : (dis[i][j] + 1);
                    if (nk > s)
                        continue;
                    if (nk < nd[nx][ny])
                        nd[nx][ny] = nk;
                }
            }
        }
        if (nd[dPos[t + 1].x][dPos[t + 1].y] < INF) {
            printf("%d\n", t + 1);
            return;
        }
        dis = move(nd);
    }

    printf("-1\n");
}

int main() {
    input();
    process();
    return 0;
}
