#include <bits/stdc++.h>
using namespace std;

int  n, m;
char s1[105], s2[105];
int  dp[105][105];
int  w[5][5] = {{5, -1, -2, -1, -3}, {-1, 5, -3, -2, -4}, {-2, -3, 5, -2, -2}, {-1, -2, -2, 5, -1}, {-3, -4, -2, -1, 0}};

int idx(char c) {
    if (c == 'A')
        return 0;
    if (c == 'C')
        return 1;
    if (c == 'G')
        return 2;
    return 3;
}

void input() {
    scanf("%d %s", &n, s1);
    scanf("%d %s", &m, s2);
}

void process() {
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i - 1][0] + w[idx(s1[i - 1])][4];
    for (int j = 1; j <= m; j++)
        dp[0][j] = dp[0][j - 1] + w[4][idx(s2[j - 1])];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int a = idx(s1[i - 1]), b = idx(s2[j - 1]);
            dp[i][j] = max(dp[i - 1][j - 1] + w[a][b], max(dp[i - 1][j] + w[a][4], dp[i][j - 1] + w[4][b]));
        }
}

void output() { printf("%d\n", dp[n][m]); }

int main() {
    input();
    process();
    output();
    return 0;
}
