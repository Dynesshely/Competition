#include <bits/stdc++.h>
using namespace std;

int a[105][105], n, m;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

void process() {}

void output() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[j][i]);
        printf("\n");
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
