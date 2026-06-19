#include <bits/stdc++.h>
using namespace std;

int a[6][6], r1, r2;

void input() {
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            scanf("%d", &a[i][j]);
    scanf("%d%d", &r1, &r2);
}

void process() {
    for (int j = 1; j <= 5; j++)
        swap(a[r1][j], a[r2][j]);
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            printf("%d%c", a[i][j], j == 5 ? '\n' : ' ');
}

int main() {
    input();
    process();
    return 0;
}
