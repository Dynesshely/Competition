#include <bits/stdc++.h>
using namespace std;

int m, n, x, sum;

void input() { scanf("%d%d", &m, &n); }

void process() {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &x);
            if (i == 1 || i == m || j == 1 || j == n)
                sum += x;
        }
    printf("%d\n", sum);
}

int main() {
    input();
    process();
    return 0;
}
