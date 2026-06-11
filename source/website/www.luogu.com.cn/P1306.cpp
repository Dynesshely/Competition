#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000000;

int n, m, g;

void input() { scanf("%d%d", &n, &m); }

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

pair<int, int> fib(int n) {
    if (n == 0)
        return {0, 1};
    auto [a, b] = fib(n >> 1);
    int c       = (1LL * a * ((2LL * b - a + MOD) % MOD)) % MOD;
    int d       = (1LL * a * a + 1LL * b * b) % MOD;
    if (n & 1)
        return {d, (c + d) % MOD};
    else
        return {c, d};
}

void process() { g = gcd(n, m); }

void output() { printf("%d\n", fib(g).first); }

int main() {
    input();
    process();
    output();
    return 0;
}
