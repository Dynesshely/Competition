#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
char      grid[MAXN][MAXN];
bool      via[MAXN][MAXN];
int       r, c, ships;
int       dx[] = {0, 0, 1, -1};
int       dy[] = {1, -1, 0, 0};

void input() {
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
        scanf("%s", grid[i] + 1);
}

bool isRect(int sr, int sc) {
    int                   minR = sr, maxR = sr, minC = sc, maxC = sc;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    via[sr][sc] = true;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        minR = min(minR, x);
        maxR = max(maxR, x);
        minC = min(minC, y);
        maxC = max(maxC, y);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && !via[nx][ny] && grid[nx][ny] == '#') {
                via[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    for (int i = minR; i <= maxR; i++)
        for (int j = minC; j <= maxC; j++)
            if (grid[i][j] != '#')
                return false;
    return true;
}

void process() {
    ships = 0;
    memset(via, 0, sizeof(via));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (grid[i][j] == '#' && !via[i][j]) {
                if (!isRect(i, j)) {
                    ships = -1;
                    return;
                }
                ships++;
            }
}

void output() {
    if (ships == -1)
        printf("Bad placement.\n");
    else
        printf("There are %d ships.\n", ships);
}

int main() {
    input();
    process();
    output();
    return 0;
}
