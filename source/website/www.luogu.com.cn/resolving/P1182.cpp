#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int a[100005];

bool check(ll x) {
    int cnt = 1;
    ll  sum = 0;
    for (int i = 1; i <= n; i++) {
        if (sum + a[i] > x) {
            cnt++;
            sum = a[i];
        } else
            sum += a[i];
    }
    return cnt <= m;
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
}

void process() {
    ll l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > l)
            l = a[i];
        r += a[i];
    }
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%lld\n", l);
}

int main() {
    input();
    process();
    return 0;
}
