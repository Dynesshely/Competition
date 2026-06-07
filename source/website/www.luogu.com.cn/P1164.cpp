#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105];
int dp[10005];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
}

void process() {
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= a[i]; j--)
            dp[j] += dp[j - a[i]];
}

void output() { printf("%d\n", dp[m]); }

int main() {
    input();
    process();
    output();
    return 0;
}
