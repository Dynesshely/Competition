#include <bits/stdc++.h>
using namespace std;

int  m, n;
bool del[11][1024];
int  col[11][1024];
int  row[11];
char g[800][1600];

void delSub(int layer, int pos) {
    if (layer > m)
        return;
    del[layer][pos] = true;
    delSub(layer + 1, 2 * pos - 1);
    delSub(layer + 1, 2 * pos);
}

void input() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        delSub(a, b);
    }
}

void process() {
    row[1] = 0;
    for (int i = 2; i <= m; i++)
        if (i == m)
            row[i] = row[i - 1] + 2;
        else
            row[i] = row[i - 1] + 3 * (1 << (m - i - 1));
    int leafCnt = 1 << (m - 1);
    for (int j = 1; j <= leafCnt; j++) {
        int idx   = j - 1;
        col[m][j] = (idx / 2) * 6 + (idx % 2) * 4;
    }
    for (int i = m - 1; i >= 1; i--) {
        int nodeCnt = 1 << (i - 1);
        for (int j = 1; j <= nodeCnt; j++)
            col[i][j] = (col[i + 1][2 * j - 1] + col[i + 1][2 * j]) / 2;
    }
    int H = row[m] + 1;
    int W = 6 * (1 << (m - 2)) - 1;
    for (int r = 0; r < H; r++)
        for (int c = 0; c < W; c++)
            g[r][c] = ' ';
    for (int i = 1; i <= m; i++) {
        int nodeCnt = 1 << (i - 1);
        for (int j = 1; j <= nodeCnt; j++) {
            if (del[i][j])
                continue;
            int r = row[i], c = col[i][j];
            g[r][c] = 'o';
            if (i < m) {
                int nxt = row[i + 1] - row[i];
                int lc = 2 * j - 1, rc = 2 * j;
                if (!del[i + 1][lc])
                    for (int k = 1; k < nxt; k++)
                        g[r + k][c - k] = '/';
                if (!del[i + 1][rc])
                    for (int k = 1; k < nxt; k++)
                        g[r + k][c + k] = '\\';
            }
        }
    }
}

void output() {
    int H = row[m] + 1;
    int W = 6 * (1 << (m - 2)) - 1;
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++)
            printf("%c", g[r][c]);
        printf("\n");
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
