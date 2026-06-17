#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int       n, m, ans, a[MAXN][MAXN * 2], b[MAXN][MAXN * 2];

void make() {
    for (int i = 1; i <= n; i++)
        if (a[n][2 * i - 1] != -1)
            a[n][2 * i - 1] = 1;
    for (int i = n - 1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            if (a[i][2 * j - 1] != -1) {
                a[i][2 * j - 1] = 1;
                if (a[i + 1][2 * j - 1] != -1 && a[i + 1][2 * j] != -1 && a[i + 1][2 * j + 1] != -1)
                    a[i][2 * j - 1] = min(a[i + 1][2 * j - 1], a[i + 1][2 * j + 1]) + 1;
            }
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i - 1; j++)
            if (a[i][2 * j] != -1) {
                a[i][2 * j] = 1;
                if (j != 1 && j != i - 1 && a[i - 1][2 * (j - 1) + 1] != -1 && a[i - 1][2 * (j - 1)] != -1 && a[i - 1][2 * j] != -1)
                    a[i][2 * j] = min(a[i - 1][2 * (j - 1)], a[i - 1][2 * j]) + 1;
            }
}

void ask() {
    for (int i = 1; i < n; i++) {
        int max1 = 0, max2 = 0;
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= j; k++)
                max1 = max(max1, min(i - j + 1, a[j][2 * k - 1]));
            for (int k = 1; k <= j - 1; k++)
                max1 = max(max1, a[j][2 * k]);
        }
        for (int j = i + 1; j <= n; j++) {
            for (int k = 1; k <= j; k++)
                max2 = max(max2, a[j][2 * k - 1]);
            for (int k = 1; k <= j - 1; k++)
                max2 = max(max2, min(j - i, a[j][2 * k]));
        }
        if (max1 != 0 && max2 != 0)
            ans = max(ans, max1 * max1 + max2 * max2);
    }
}

void splay() {
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            if (a[i][2 * j - 1] == -1)
                b[n - i + j][(n - i) * 2 + 1] = -1;
        for (int j = 1; j <= i - 1; j++)
            if (a[i][2 * j] == -1)
                b[n - i + j + 1][(n - i) * 2 + 2] = -1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 2 * i - 1; j++)
            a[i][j] = b[i][j];
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] = -1;
    }
}

void process() {
    for (int t = 0; t < 3; t++) {
        make();
        ask();
        splay();
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
