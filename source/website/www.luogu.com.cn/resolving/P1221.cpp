#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
ll  bestNum, bestDiv, l, u;

void dfs(int idx, ll cur, int curDiv, int lastExp) {
    if (cur > u)
        return;
    if (cur >= l) {
        if (curDiv > bestDiv || (curDiv == bestDiv && cur < bestNum)) {
            bestDiv = curDiv;
            bestNum = cur;
        }
    }
    if (idx >= 15)
        return;
    ll p   = primes[idx];
    ll nxt = cur;
    for (int e = 0; e <= lastExp; ++e) {
        if (nxt > u / p)
            break;
        nxt *= p;
        dfs(idx + 1, nxt, curDiv * (e + 2), e);
    }
}

int main() {
    scanf("%lld%lld", &l, &u);
    bestNum = l;
    bestDiv = 0;
    for (ll i = l; i <= u && i - l < 100000; ++i) {
        ll  x = i;
        int d = 1;
        for (int p = 2; p * p <= x; ++p) {
            if (x % p == 0) {
                int c = 0;
                while (x % p == 0) {
                    x /= p;
                    ++c;
                }
                d *= (c + 1);
            }
        }
        if (x > 1)
            d *= 2;
        if (d > bestDiv) {
            bestDiv = d;
            bestNum = i;
        }
    }
    dfs(0, 1, 1, 30);
    if (bestNum < l) {
        bestNum = l;
        bestDiv = 0;
        for (ll i = l; i <= u; ++i) {
            ll  x = i;
            int d = 1;
            for (int p = 2; p * p <= x; ++p) {
                if (x % p == 0) {
                    int c = 0;
                    while (x % p == 0) {
                        x /= p;
                        ++c;
                    }
                    d *= (c + 1);
                }
            }
            if (x > 1)
                d *= 2;
            if (d > bestDiv) {
                bestDiv = d;
                bestNum = i;
            }
        }
    }
    printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", l, u, bestNum, bestDiv);
    return 0;
}
