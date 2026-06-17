#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

char s[MAXN], t[MAXN];
int  dp[MAXN][MAXN];
int  n;

void input() {
    scanf("%s", s);
    n = strlen(s);
}

void process() {
    for (int i = 0; i < n; i++)
        t[i] = s[n - 1 - i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

void output() { printf("%d\n", n - dp[n][n]); }

int main() {
    input();
    process();
    output();
    return 0;
}
