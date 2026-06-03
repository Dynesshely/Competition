#include <bits/stdc++.h>
using namespace std;

const int w[9][9] = {
    {6,6,6,6,6,6,6,6,6},{6,7,7,7,7,7,7,7,6},{6,7,8,8,8,8,8,7,6},
    {6,7,8,9,9,9,8,7,6},{6,7,8,9,10,9,8,7,6},{6,7,8,9,9,9,8,7,6},
    {6,7,8,8,8,8,8,7,6},{6,7,7,7,7,7,7,7,6},{6,6,6,6,6,6,6,6,6}
};

int a[9][9], row[9], col[9], blk[9], ans = -1;

inline int getBlk(int i, int j) { return (i / 3) * 3 + j / 3; }

void dfs() {
    int minCnt = 10, mi = -1, mj = -1;
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            if (a[i][j] == 0) {
                int mask = row[i] | col[j] | blk[getBlk(i, j)], cnt = 0;
                for (int d = 1; d <= 9; ++d) if (!(mask & (1 << d))) ++cnt;
                if (cnt < minCnt) { minCnt = cnt; mi = i; mj = j; }
            }
    if (mi == -1) {
        int score = 0;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) score += a[i][j] * w[i][j];
        if (score > ans) ans = score;
        return;
    }
    if (minCnt == 0) return;
    int mask = row[mi] | col[mj] | blk[getBlk(mi, mj)];
    for (int d = 1; d <= 9; ++d) {
        if (mask & (1 << d)) continue;
        a[mi][mj] = d;
        row[mi] |= (1 << d); col[mj] |= (1 << d); blk[getBlk(mi, mj)] |= (1 << d);
        dfs();
        a[mi][mj] = 0;
        row[mi] &= ~(1 << d); col[mj] &= ~(1 << d); blk[getBlk(mi, mj)] &= ~(1 << d);
    }
}

int main() {
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j]) {
                int d = a[i][j];
                row[i] |= (1 << d); col[j] |= (1 << d); blk[getBlk(i, j)] |= (1 << d);
            }
        }
    dfs();
    printf("%d\n", ans);
    return 0;
}
