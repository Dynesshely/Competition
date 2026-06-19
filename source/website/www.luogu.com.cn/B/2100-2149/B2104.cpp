#include <bits/stdc++.h>
using namespace std;

int n, m, a[105][105], b;

void input() { scanf("%d%d", &n, &m); }

void process() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &b);
            a[i][j] += b;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            printf("%d%c", a[i][j], j == m ? '\n' : ' ');
}

int main() {
    input();
    process();
    return 0;
}
