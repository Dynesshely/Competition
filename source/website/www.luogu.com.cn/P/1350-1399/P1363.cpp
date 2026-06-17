#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1505;
const int DX[] = {0, 0, 1, -1};
const int DY[] = {1, -1, 0, 0};

int  n, m, cur;
char grid[MAXN][MAXN];
int  via[MAXN][MAXN];
int  rX[MAXN][MAXN];
int  rY[MAXN][MAXN];
int  sx, sy;

void input() {
    cur++;
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'S') {
                sx         = i;
                sy         = j;
                grid[i][j] = '.';
            }
    }
}

bool process() {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    via[sx][sy] = cur;
    rX[sx][sy]  = sx;
    rY[sx][sy]  = sy;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + DX[d];
            int ny = y + DY[d];
            int rx = nx % n;
            if (rx < 0)
                rx += n;
            int ry = ny % m;
            if (ry < 0)
                ry += m;
            if (grid[rx][ry] == '#')
                continue;
            if (via[rx][ry] != cur) {
                via[rx][ry] = cur;
                rX[rx][ry]  = nx;
                rY[rx][ry]  = ny;
                q.push({nx, ny});
            } else if (rX[rx][ry] != nx || rY[rx][ry] != ny)
                return true;
        }
    }
    return false;
}

void output() {
    if (process())
        printf("Yes\n");
    else
        printf("No\n");
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        input();
        output();
    }
    return 0;
}
