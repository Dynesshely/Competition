#include <bits/stdc++.h>
using namespace std;

int dp[300005];

int main() {
    int m, s, t;
    scanf("%d%d%d", &m, &s, &t);
    int magic = m;
    for (int i = 1; i <= t; ++i) {
        if (magic >= 10) { magic -= 10; dp[i] = dp[i - 1] + 60; }
        else { magic += 4; dp[i] = dp[i - 1]; }
    }
    for (int i = 1; i <= t; ++i) {
        if (dp[i] < dp[i - 1] + 17) dp[i] = dp[i - 1] + 17;
        if (dp[i] >= s) { printf("Yes\n%d\n", i); return 0; }
    }
    printf("No\n%d\n", dp[t]);
    return 0;
}
