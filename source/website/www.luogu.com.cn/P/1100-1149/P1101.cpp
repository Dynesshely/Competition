#include <bits/stdc++.h>
using namespace std;

const char word[]    = "yizhong";
const int  dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int  n;
char g[105][105];
bool mark[105][105];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", g[i]);
}

void process() {
    memset(mark, 0, sizeof(mark));
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            for (int d = 0; d < 8; d++) {
                int dx = dir[d][0], dy = dir[d][1];
                int nr = r + 6 * dx, nc = c + 6 * dy;
                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;
                bool ok = true;
                for (int k = 0; k < 7; k++)
                    if (g[r + k * dx][c + k * dy] != word[k]) {
                        ok = false;
                        break;
                    }
                if (ok)
                    for (int k = 0; k < 7; k++)
                        mark[r + k * dx][c + k * dy] = true;
            }
}

void output() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c", mark[i][j] ? g[i][j] : '*');
        printf("\n");
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
