#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll count_no7(ll n) {
    if (n <= 0) return 0;
    vector<int> d;
    for (ll t = n; t; t /= 10) d.push_back(t % 10);
    reverse(d.begin(), d.end());
    int m = d.size();
    vector dp(m + 1, vector<ll>(2, 0));
    dp[0][1] = 1;
    for (int i = 0; i < m; ++i) {
        for (int tight = 0; tight < 2; ++tight) {
            if (dp[i][tight] == 0) continue;
            int lim = tight ? d[i] : 9;
            for (int c = 0; c <= lim; ++c) {
                if (c == 7) continue;
                dp[i + 1][tight && c == lim] += dp[i][tight];
            }
        }
    }
    return dp[m][0] + dp[m][1] - 1;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", count_no7(n));
    }
    return 0;
}
