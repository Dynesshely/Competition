#include <bits/stdc++.h>
using namespace std;

int grid[4][4], rowSum[4], colSum[4], diag0, diag1;
int known[4][3];

int main() {
    for (int i = 0; i < 4; ++i)
        scanf("%d", &rowSum[i]);
    for (int i = 0; i < 4; ++i)
        scanf("%d", &colSum[i]);
    scanf("%d%d", &diag0, &diag1);
    for (int i = 0; i < 4; ++i)
        scanf("%d%d%d", &known[i][0], &known[i][1], &known[i][2]);
    memset(grid, 0, sizeof(grid));
    for (int i = 0; i < 4; ++i)
        grid[known[i][0]][known[i][1]] = known[i][2];
    double a[16][17] = {};
    int    eq        = 0;
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c)
            a[eq][r * 4 + c] = 1;
        a[eq][16] = rowSum[r];
        ++eq;
    }
    for (int c = 0; c < 4; ++c) {
        for (int r = 0; r < 4; ++r)
            a[eq][r * 4 + c] = 1;
        a[eq][16] = colSum[c];
        ++eq;
    }
    a[eq][0] = a[eq][5] = a[eq][10] = a[eq][15] = 1;
    a[eq][16]                                   = diag0;
    ++eq;
    a[eq][3] = a[eq][6] = a[eq][9] = a[eq][12] = 1;
    a[eq][16]                                  = diag1;
    ++eq;
    bool fixed[16] = {};
    for (int i = 0; i < 4; ++i) {
        int pos    = known[i][0] * 4 + known[i][1];
        a[eq][pos] = 1;
        a[eq][16]  = known[i][2];
        fixed[pos] = true;
        ++eq;
    }
    int n = 16, m = eq;
    for (int col = 0, row = 0; col < n && row < m; ++col) {
        int sel = row;
        for (int i = row; i < m; ++i)
            if (fabs(a[i][col]) > fabs(a[sel][col]))
                sel = i;
        if (fabs(a[sel][col]) < 1e-9)
            continue;
        for (int j = col; j <= n; ++j)
            swap(a[row][j], a[sel][j]);
        for (int i = 0; i < m; ++i)
            if (i != row && fabs(a[i][col]) > 1e-9) {
                double f = a[i][col] / a[row][col];
                for (int j = col; j <= n; ++j)
                    a[i][j] -= f * a[row][j];
            }
        ++row;
    }
    double x[16] = {};
    for (int i = 0; i < 16; ++i)
        x[i] = 1;
    for (int i = m - 1; i >= 0; --i) {
        int pivot = -1;
        for (int j = 0; j < n; ++j)
            if (fabs(a[i][j]) > 1e-9) {
                pivot = j;
                break;
            }
        if (pivot == -1)
            continue;
        double val = a[i][n];
        for (int j = pivot + 1; j < n; ++j)
            val -= a[i][j] * x[j];
        x[pivot] = val / a[i][pivot];
        if (x[pivot] < 1)
            x[pivot] = 1;
    }
    for (int i = 0; i < 16; ++i) {
        int v = (int)(x[i] + 0.5);
        if (v < 1)
            v = 1;
        grid[i / 4][i % 4] = v;
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}
