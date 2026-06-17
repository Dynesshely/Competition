#include <bits/stdc++.h>
using namespace std;

const int MOD  = 1000000007;
const int MAXN = 100;
const int MAXS = 25 * MAXN;
const int MAXF = MAXS + MAXN;

long long fact[MAXF + 1], invFact[MAXF + 1];

long long modPow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXF; i++)
        fact[i] = fact[i - 1] * i % MOD;
    invFact[MAXF] = modPow(fact[MAXF], MOD - 2);
    for (int i = MAXF; i >= 1; i--)
        invFact[i - 1] = invFact[i] * i % MOD;
}

long long C(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

void input() {
    init();
    int T;
    scanf("%d", &T);
    char s[105];
    while (T--) {
        scanf("%s", s);
        int n   = strlen(s);
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += s[i] - 'a';
        long long total = 0;
        int       maxK  = min(n, sum / 26);
        for (int k = 0; k <= maxK; k++) {
            long long term = C(n, k) * C(sum - 26 * k + n - 1, n - 1) % MOD;
            if (k & 1)
                total = (total - term + MOD) % MOD;
            else
                total = (total + term) % MOD;
        }
        long long ans = (total - 1 + MOD) % MOD;
        printf("%lld\n", ans);
    }
}

int main() {
    input();
    return 0;
}
