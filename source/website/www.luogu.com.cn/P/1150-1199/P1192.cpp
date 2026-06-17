#include <bits/stdc++.h>
using namespace std;

const int MOD = 100003;

int         n, k;
vector<int> dp;

void input() { scanf("%d%d", &n, &k); }

void process() {
    dp.resize(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k && i - j >= 0; j++)
            dp[i] = (dp[i] + dp[i - j]) % MOD;
}

void output() { printf("%d\n", dp[n]); }

int main() {
    input();
    process();
    output();
    return 0;
}
