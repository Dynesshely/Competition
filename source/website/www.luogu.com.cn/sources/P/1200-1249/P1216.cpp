#include <bits/stdc++.h>
using namespace std;

int r, a[1005][1005];

void input() {
    scanf("%d", &r);
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
}

void process() {
    for (int i = r - 1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
}

void output() { printf("%d\n", a[1][1]); }

int main() {
    input();
    process();
    output();
    return 0;
}
