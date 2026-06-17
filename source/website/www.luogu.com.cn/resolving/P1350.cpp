#include <bits/stdc++.h>
using namespace std;

const int MOD  = 100003;
const int MAXN = 1000;

int fact[MAXN + 1], invFact[MAXN + 1];

int powMod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = (long long)res * a % MOD;
        a = (long long)a * a % MOD;
        b >>= 1;
    }
    return res;
}

int C(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    return (long long)fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int a, b, c, d, k;

void input() { scanf("%d%d%d%d%d", &a, &b, &c, &d, &k); }

void process() {
    int maxN = max(max(max(a, b), max(c, d)), k);
    fact[0]  = 1;
    for (int i = 1; i <= maxN; i++)
        fact[i] = (long long)fact[i - 1] * i % MOD;
    invFact[maxN] = powMod(fact[maxN], MOD - 2);
    for (int i = maxN - 1; i >= 0; i--)
        invFact[i] = (long long)invFact[i + 1] * (i + 1) % MOD;
}

void output() {
    int ans = 0;
    for (int p = 0; p <= min(a, min(b, k)); p++)
        for (int q = 0; q <= min(d, min(b - p, k - p)); q++) {
            int r = k - p - q;
            if (r < 0 || r > c || r > d - q)
                continue;
            long long term = (long long)C(b, p + q) * C(p + q, p) % MOD;
            term           = term * C(c, r) % MOD;
            term           = term * C(a, p) % MOD;
            term           = term * C(d, q + r) % MOD;
            term           = term * C(q + r, q) % MOD;
            term           = term * fact[p] % MOD * fact[q] % MOD * fact[r] % MOD;
            ans            = (ans + term) % MOD;
        }
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
