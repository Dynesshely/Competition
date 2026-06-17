#include <bits/stdc++.h>
using namespace std;

int          n;
vector<int>  a;
vector<bool> zeroTower;

int phi(int x) {
    int res = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        res = res / x * (x - 1);
    return res;
}

int powMod(int x, int y, int m) {
    int res = 1 % m;
    x %= m;
    while (y) {
        if (y & 1)
            res = (long long)res * x % m;
        x = (long long)x * x % m;
        y >>= 1;
    }
    return res;
}

bool checkLarge(int base, int exp, int m) {
    if (exp == 0)
        return 1 >= m;
    if (base >= m)
        return true;
    long long cur = 1;
    for (int i = 0; i < exp && i < 30; i++) {
        if (cur > m / base)
            return true;
        cur *= base;
        if (cur >= m)
            return true;
    }
    return false;
}

pair<int, bool> solve(int idx, int m) {
    if (m == 1)
        return {0, !zeroTower[idx]};
    if (idx == n) {
        int val = a[idx] % m;
        return {val, a[idx] >= m};
    }
    int  nextM  = phi(m);
    auto sub    = solve(idx + 1, nextM);
    int  e      = sub.first;
    bool eLarge = sub.second;
    int  base   = a[idx];
    if (base == 0) {
        if (e == 0 && !eLarge)
            return {1 % m, false};
        return {0, false};
    }
    if (base == 1)
        return {1 % m, false};
    int g = __gcd(base, m);
    int exp;
    if (g == 1)
        exp = e;
    else {
        if (eLarge)
            exp = e + nextM;
        else
            exp = e;
    }
    int  val = powMod(base, exp, m);
    bool large;
    if (eLarge)
        large = true;
    else
        large = checkLarge(base, e, m);
    return {val, large};
}

void input() {
    scanf("%d", &n);
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    zeroTower.resize(n + 2);
    zeroTower[n + 1] = false;
    for (int i = n; i >= 1; i--)
        zeroTower[i] = (a[i] == 0) && !zeroTower[i + 1];
}

void process() {}

void output() {
    auto res = solve(1, 10007);
    printf("%d\n", res.first);
}

int main() {
    input();
    process();
    output();
    return 0;
}
