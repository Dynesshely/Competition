#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n, r;
ld sq;

inline ll G(ll a, ll b) { return b ? G(b, a % b) : a; }

ll F(ll a, ll b, ll c, ll n) {
    if (!n)
        return 0;

    ll g = G(abs(a), G(abs(b), abs(c)));
    a /= g;
    b /= g;
    c /= g;

    ll k = (ll)((a * sq + b) / c);

    if (k)
        return k * (n * (n + 1) / 2) + F(a, b - k * c, c, n);

    ll m = (ll)(((a * sq + b) / c) * n);

    return m * n - F(a * c, -b * c, a * a * r - b * b, m);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%lld%lld", &n, &r);

        sq = sqrt((ld)r);

        ll t = (ll)sq;

        if (t * t == r) {
            if (t & 1)
                printf("%lld\n", (n & 1) ? -1LL : 0LL);
            else
                printf("%lld\n", n);
            continue;
        }

        printf("%lld\n", n - 2 * F(1, 0, 1, n) + 4 * F(1, 0, 2, n));
    }

    return 0;
}