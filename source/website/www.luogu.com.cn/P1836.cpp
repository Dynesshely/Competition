#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n, ans = 0;
    scanf("%lld", &n);
    for (ll p = 1; p <= n; p *= 10) {
        ll cycles = n / (p * 10);
        ans += cycles * 45 * p;
        ll rem = n % (p * 10);
        for (ll d = 1; d <= 9; ++d) {
            ll cnt = min(max(0LL, rem - d * p + 1), p);
            ans += d * cnt;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
