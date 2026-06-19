#include <bits/stdc++.h>
using namespace std;

int m, n, a[105][105], b, same;

void input() { scanf("%d%d", &m, &n); }

void process() {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &b);
            if (a[i][j] == b)
                ++same;
        }
    printf("%.2f\n", 100.0 * same / (m * n));
}

int main() {
    input();
    process();
    return 0;
}
