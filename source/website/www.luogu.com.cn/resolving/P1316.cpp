#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

long long powMod(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    long long invM = powMod(m, MOD - 2);
    long long powM[21], powInvM[21];
    powM[0] = powInvM[0] = 1;
    for (int i = 1; i <= n; i++) {
        powM[i]    = powM[i - 1] * m % MOD;
        powInvM[i] = powInvM[i - 1] * invM % MOD;
    }

    long long ans = 0;
    for (int k = 1; k <= n; k++) {
        int N     = n - k + 1;
        int total = 1 << N;
        for (int mask = 1; mask < total; mask++) {
            int pop = __builtin_popcount(mask);

            int f = 0, prevEnd = -1;
            for (int i = 0; i < N; i++)
                if (mask & (1 << i)) {
                    int end = i + k;
                    if (prevEnd == -1) {
                        f       = k;
                        prevEnd = end;
                    } else if (i + 1 > prevEnd) {
                        f += k;
                        prevEnd = end;
                    } else if (end > prevEnd) {
                        f += end - prevEnd;
                        prevEnd = end;
                    }
                }

            int h;
            if (pop == 1) {
                h = k;
            } else {
                int first = -1, g = 0;
                for (int i = 0; i < N; i++)
                    if (mask & (1 << i)) {
                        if (first == -1)
                            first = i + 1;
                        else
                            g = __gcd(g, i + 1 - first);
                    }
                h = min(g, k);
            }

            long long term = powM[h] * powInvM[f] % MOD;
            if (pop % 2 == 0)
                term = MOD - term;
            ans = (ans + term) % MOD;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
