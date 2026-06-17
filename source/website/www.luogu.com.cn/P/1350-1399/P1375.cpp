#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int n, ans;

int powMod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

void input() { scanf("%d", &n); }

void process() {
    int         m = 2 * n;
    vector<int> fac(m + 1), invFac(m + 1);
    fac[0] = 1;
    for (int i = 1; i <= m; ++i)
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    invFac[m] = powMod(fac[m], MOD - 2);
    for (int i = m; i >= 1; --i)
        invFac[i - 1] = 1LL * invFac[i] * i % MOD;
    int c = 1LL * fac[m] * invFac[n] % MOD * invFac[n] % MOD;
    ans   = 1LL * c * powMod(n + 1, MOD - 2) % MOD;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
