#include <bits/stdc++.h>
using namespace std;

int    n, len[45], total;
double ans = -1;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &len[i]);
        total += len[i];
    }
}

void process() {
    const int                maxS = 1600;
    vector<bitset<maxS + 1>> dp(maxS + 1);
    dp[0][0] = 1;
    for (int idx = 0; idx < n; ++idx) {
        int                      x   = len[idx];
        vector<bitset<maxS + 1>> pre = dp;
        for (int i = total; i >= x; --i)
            dp[i] |= pre[i - x];
        for (int i = 0; i <= total; ++i)
            dp[i] |= pre[i] << x;
    }
    for (int a = 1; a <= total; ++a) {
        for (int b = 1; b <= total; ++b) {
            if (!dp[a][b])
                continue;
            int c = total - a - b;
            if (c <= 0)
                continue;
            if (a + b <= c || a + c <= b || b + c <= a)
                continue;
            double s    = total / 2.0;
            double area = sqrt(s * (s - a) * (s - b) * (s - c));
            if (area > ans)
                ans = area;
        }
    }
}

void output() {
    if (ans < 0)
        printf("-1\n");
    else
        printf("%d\n", (int)(ans * 100 + 1e-9));
}

int main() {
    input();
    process();
    output();
    return 0;
}
