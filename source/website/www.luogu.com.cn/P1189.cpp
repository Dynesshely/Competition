#include <bits/stdc++.h>
using namespace std;

int  R, C, N;
char grid[55][55];
bool cur[55][55], nxt[55][55];

void input() {
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++) {
        scanf("%s", grid[i]);
    }
    scanf("%d", &N);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '*') {
                cur[i][j]  = true;
                grid[i][j] = '.';
            }
        }
    }
}

void process() {
    char dir[10];
    for (int step = 0; step < N; step++) {
        scanf("%s", dir);
        memset(nxt, 0, sizeof(nxt));
        if (dir[0] == 'N') {
            for (int c = 0; c < C; c++) {
                int lastSrc = -1;
                for (int r = R - 1; r >= 0; r--) {
                    if (grid[r][c] == 'X') {
                        lastSrc = -1;
                    } else if (cur[r][c]) {
                        if (lastSrc != -1 && r < lastSrc)
                            nxt[r][c] = true;
                        lastSrc = r;
                    } else if (lastSrc != -1) {
                        nxt[r][c] = true;
                    }
                }
            }
        } else if (dir[0] == 'S') {
            for (int c = 0; c < C; c++) {
                int lastSrc = -1;
                for (int r = 0; r < R; r++) {
                    if (grid[r][c] == 'X') {
                        lastSrc = -1;
                    } else if (cur[r][c]) {
                        if (lastSrc != -1 && r > lastSrc)
                            nxt[r][c] = true;
                        lastSrc = r;
                    } else if (lastSrc != -1) {
                        nxt[r][c] = true;
                    }
                }
            }
        } else if (dir[0] == 'W') {
            for (int r = 0; r < R; r++) {
                int lastSrc = -1;
                for (int c = C - 1; c >= 0; c--) {
                    if (grid[r][c] == 'X') {
                        lastSrc = -1;
                    } else if (cur[r][c]) {
                        if (lastSrc != -1 && c < lastSrc)
                            nxt[r][c] = true;
                        lastSrc = c;
                    } else if (lastSrc != -1) {
                        nxt[r][c] = true;
                    }
                }
            }
        } else {
            for (int r = 0; r < R; r++) {
                int lastSrc = -1;
                for (int c = 0; c < C; c++) {
                    if (grid[r][c] == 'X') {
                        lastSrc = -1;
                    } else if (cur[r][c]) {
                        if (lastSrc != -1 && c > lastSrc)
                            nxt[r][c] = true;
                        lastSrc = c;
                    } else if (lastSrc != -1) {
                        nxt[r][c] = true;
                    }
                }
            }
        }
        memcpy(cur, nxt, sizeof(cur));
    }
}

void output() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c", cur[i][j] ? '*' : grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
