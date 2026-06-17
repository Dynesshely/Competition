#include <bits/stdc++.h>
using namespace std;

int  n, s;
int  a[20];
int  grid[4][4];
bool used[20];
int  rowSum[4], colSum[4];
int  diag1, diag2;
bool done;

void dfs(int p) {
    if (done)
        return;
    if (p == n * n) {
        if (diag1 == s && diag2 == s)
            done = true;
        return;
    }
    int r = p / n, c = p % n;
    for (int i = 0; i < n * n; i++) {
        if (used[i])
            continue;
        if (i > 0 && a[i] == a[i - 1] && !used[i - 1])
            continue;
        int v = a[i];
        if (c == n - 1) {
            int need = s - rowSum[r];
            if (v != need)
                continue;
        }
        if (r == n - 1) {
            int need = s - colSum[c];
            if (v != need)
                continue;
        }
        if (r == n - 1 && c == 0) {
            int need = s - diag2;
            if (v != need)
                continue;
        }
        if (r == n - 1 && c == n - 1) {
            int need = s - diag1;
            if (v != need)
                continue;
        }
        used[i]    = true;
        grid[r][c] = v;
        rowSum[r] += v;
        colSum[c] += v;
        if (r == c)
            diag1 += v;
        if (r + c == n - 1)
            diag2 += v;
        dfs(p + 1);
        if (done)
            return;
        used[i] = false;
        rowSum[r] -= v;
        colSum[c] -= v;
        if (r == c)
            diag1 -= v;
        if (r + c == n - 1)
            diag2 -= v;
    }
}

int main() {
    scanf("%d", &n);
    int m = n * n, total = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        total += a[i];
    }
    s = total / n;
    sort(a, a + m);
    dfs(0);
    printf("%d\n", s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d%c", grid[i][j], j == n - 1 ? '\n' : ' ');
    }
    return 0;
}
