#include <bits/stdc++.h>
using namespace std;

int n, m, a[2005][2005], ans;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
}

void process() {
    vector<int> dp(m);
    for (int i = 0; i < m; ++i)
        dp[i] = a[i][0];
    for (int j = 1; j < n; ++j) {
        vector<int> ndp(m);
        for (int i = 0; i < m; ++i)
            ndp[i] = a[i][j] + min(dp[i], dp[(i - 1 + m) % m]);
        dp = move(ndp);
    }
    ans = *min_element(dp.begin(), dp.end());
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
