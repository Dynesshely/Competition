#include <bits/stdc++.h>
using namespace std;

int m, s, c;
int a[210], gap[210];

void input() {
    scanf("%d%d%d", &m, &s, &c);
    for (int i = 0; i < c; i++)
        scanf("%d", &a[i]);
}

void process() {
    sort(a, a + c);
    for (int i = 1; i < c; i++)
        gap[i] = a[i] - a[i - 1] - 1;
    sort(gap + 1, gap + c, greater<int>());
}

void output() {
    if (m >= c) {
        printf("%d\n", c);
        return;
    }
    int ans = a[c - 1] - a[0] + 1;
    for (int i = 1; i <= m - 1; i++)
        ans -= gap[i];
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
