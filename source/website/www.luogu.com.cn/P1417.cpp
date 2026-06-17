#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Item {
    ll a, b, c;
};

bool cmp(const Item &x, const Item &y) { return x.c * y.b < y.c * x.b; }

int  T, n;
Item items[55];
ll   dp[100005];

void input() {
    scanf("%d%d", &T, &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &items[i].a);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &items[i].b);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &items[i].c);
}

void process() {
    sort(items + 1, items + n + 1, cmp);
    memset(dp, 0xc0, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll a = items[i].a, b = items[i].b, c = items[i].c;
        for (int t = T; t >= c; t--)
            dp[t] = max(dp[t], dp[t - c] + a - t * b);
    }
}

void output() {
    ll ans = 0;
    for (int t = 0; t <= T; t++)
        ans = max(ans, dp[t]);
    printf("%lld\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
