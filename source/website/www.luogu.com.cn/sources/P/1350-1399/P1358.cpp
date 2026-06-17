#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;

int fac[10010], invFac[10010];
int a[110], n, m, ans;

int qpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
}

void process() {
    int sumA = 0;
    for (int i = 1; i <= m; ++i)
        sumA += a[i];
    if (sumA > n) {
        ans = 0;
        return;
    }
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = fac[i - 1] * i % MOD;
    invFac[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i)
        invFac[i] = invFac[i + 1] * (i + 1) % MOD;
    ans = fac[n];
    for (int i = 1; i <= m; ++i)
        ans = ans * invFac[a[i]] % MOD;
    ans = ans * invFac[n - sumA] % MOD;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
