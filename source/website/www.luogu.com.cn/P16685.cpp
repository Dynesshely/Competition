#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);

        vector<int> cnt(n + 1, 0);

        long long ans = 1;
        for (int i = 1; i <= n; ++i) {
            int s;
            scanf("%d", &s);
            if (ans != 0) {
                int c = cnt[s];
                if (c == m)
                    ans = 0;
                else
                    ans = ans * (m - c) % MOD;
                cnt[s] = c + 1;
            }
            printf("%lld%c", ans, " \n"[i == n]);
        }
    }

    return 0;
}
