#include <bits/stdc++.h>
using namespace std;

int n, r, c;

void input() { scanf("%d%d%d", &n, &r, &c); }

void process() {
    for (int j = 1; j <= n; j++)
        printf("(%d,%d)%c", r, j, j == n ? '\n' : ' ');
    for (int i = 1; i <= n; i++)
        printf("(%d,%d)%c", i, c, i == n ? '\n' : ' ');
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i - j == r - c)
                printf("(%d,%d) ", i, j);
    printf("\n");
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= n; j++)
            if (i + j == r + c)
                printf("(%d,%d) ", i, j);
    printf("\n");
}

int main() {
    input();
    process();
    return 0;
}
