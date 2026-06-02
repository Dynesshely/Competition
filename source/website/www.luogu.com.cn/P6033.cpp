#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXA = 100005;
int cnt[MAXA];
ll q2[10000005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int p = 1;
    while (p < MAXA && cnt[p] == 0) p++;
    int qh = 0, qt = 0;
    ll ans = 0;
    auto get = [&]() -> ll {
        if (p < MAXA && (qh == qt || p <= q2[qh])) {
            ll v = p;
            if (--cnt[p] == 0)
                while (++p < MAXA && cnt[p] == 0);
            return v;
        }
        return q2[qh++];
    };
    for (int i = 1; i < n; ++i) {
        ll a = get();
        ll b = get();
        ll s = a + b;
        ans += s;
        q2[qt++] = s;
    }
    printf("%lld\n", ans);
    return 0;
}
