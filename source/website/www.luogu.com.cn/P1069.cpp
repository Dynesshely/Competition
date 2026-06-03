#include <bits/stdc++.h>
using namespace std;

int primes[10005], pcnt, expM[10005];

int main() {
    int n, m1, m2;
    scanf("%d%d%d", &n, &m1, &m2);
    int tmp = m1;
    for (int p = 2; p * p <= tmp; ++p) {
        if (tmp % p == 0) {
            primes[pcnt] = p;
            while (tmp % p == 0) { ++expM[pcnt]; tmp /= p; }
            expM[pcnt] *= m2;
            ++pcnt;
        }
    }
    if (tmp > 1) { primes[pcnt] = tmp; expM[pcnt] = m2; ++pcnt; }
    int ans = 0x7fffffff;
    for (int i = 0; i < n; ++i) {
        int s;
        scanf("%d", &s);
        int maxT = 0;
        bool ok = true;
        for (int j = 0; j < pcnt; ++j) {
            int p = primes[j], e = 0;
            while (s % p == 0) { ++e; s /= p; }
            if (e == 0) { ok = false; break; }
            int t = (expM[j] + e - 1) / e;
            if (t > maxT) maxT = t;
        }
        if (ok && maxT < ans) ans = maxT;
    }
    printf("%d\n", ans == 0x7fffffff ? -1 : ans);
    return 0;
}
