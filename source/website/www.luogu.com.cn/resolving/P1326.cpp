#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll s, t, n;

void input() { scanf("%lld%lld%lld", &s, &t, &n); }

void process() {
    ll maxW = min(n, s);
    ll maxP = 3 * maxW + min(n - maxW, min(s - maxW, t));
    ll minL = min(n, t);
    ll minD = min(n - minL, min(s, t - minL));
    ll minP = minD + 3 * (n - minL - minD);
    printf("%lld %lld\n", maxP, minP);
}

int main() {
    while (scanf("%lld%lld%lld", &s, &t, &n) == 3)
        process();
    return 0;
}
