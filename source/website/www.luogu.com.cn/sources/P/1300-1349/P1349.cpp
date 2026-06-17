#include <bits/stdc++.h>
using namespace std;

struct Mat {
    long long a, b, c, d;
    Mat(long long a, long long b, long long c, long long d)
        : a(a)
        , b(b)
        , c(c)
        , d(d) {}
};

Mat mul(Mat x, Mat y, long long mod) { return Mat((x.a * y.a + x.b * y.c) % mod, (x.a * y.b + x.b * y.d) % mod, (x.c * y.a + x.d * y.c) % mod, (x.c * y.b + x.d * y.d) % mod); }

Mat pow(Mat base, long long exp, long long mod) {
    Mat res(1, 0, 0, 1);
    while (exp) {
        if (exp & 1)
            res = mul(res, base, mod);
        base = mul(base, base, mod);
        exp >>= 1;
    }
    return res;
}

long long p, q, a1, a2, n, m;

void input() { scanf("%lld%lld%lld%lld%lld%lld", &p, &q, &a1, &a2, &n, &m); }

void process() {
    if (n == 1) {
        printf("%lld\n", a1 % m);
        return;
    }
    if (n == 2) {
        printf("%lld\n", a2 % m);
        return;
    }
    Mat       base(p % m, q % m, 1, 0);
    Mat       mat = pow(base, n - 2, m);
    long long ans = (mat.a * (a2 % m) + mat.b * (a1 % m)) % m;
    printf("%lld\n", ans);
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
