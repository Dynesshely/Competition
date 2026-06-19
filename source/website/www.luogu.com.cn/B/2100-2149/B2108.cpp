#include <bits/stdc++.h>
using namespace std;

int a[105][105], b[105][105], n, m;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

void process() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                b[i][j] = a[i][j];
            else {
                int sum = a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1];
                b[i][j] = (sum + 2) / 5;
            }
        }
}

void output() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
