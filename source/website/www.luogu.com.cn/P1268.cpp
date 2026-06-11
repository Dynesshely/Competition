#include <bits/stdc++.h>
using namespace std;

int n, m[35][35];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            scanf("%d", &m[i][j]);
}

void process() {
    int ans = m[1][2];
    for (int k = 3; k <= n; k++) {
        int add = 1e9;
        for (int i = 2; i < k; i++)
            add = min(add, (m[1][k] + m[i][k] - m[1][i]) / 2);
        ans += add;
    }
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
