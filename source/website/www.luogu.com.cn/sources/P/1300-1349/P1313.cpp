#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;

int a, b, k, n, m;
int c[1005][1005];

int powMod(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp) {
        if (exp & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

void input() { scanf("%d%d%d%d%d", &a, &b, &k, &n, &m); }

void process() {
    for (int i = 0; i <= k; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
}

void output() {
    int ans = c[k][m] * powMod(a, n) % MOD * powMod(b, m) % MOD;
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
