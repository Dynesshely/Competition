#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n, m;
ll  s;
int w[MAXN], v[MAXN];
int l[MAXN], r[MAXN];
ll  cntPref[MAXN], valPref[MAXN];

ll calc(int W) {
    for (int i = 1; i <= n; i++) {
        cntPref[i] = cntPref[i - 1] + (w[i] >= W ? 1 : 0);
        valPref[i] = valPref[i - 1] + (w[i] >= W ? v[i] : 0);
    }
    ll res = 0;
    for (int i = 1; i <= m; i++)
        res += (cntPref[r[i]] - cntPref[l[i] - 1]) * (valPref[r[i]] - valPref[l[i] - 1]);
    return res;
}

void input() {
    scanf("%d%d%lld", &n, &m, &s);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &w[i], &v[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &l[i], &r[i]);
}

void process() {
    ll  ans = 1ll << 60;
    int lo = 0, hi = 1000005;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        ll  y   = calc(mid);
        if (y > s)
            lo = mid + 1;
        else
            hi = mid - 1;
        ll diff = y > s ? y - s : s - y;
        if (diff < ans)
            ans = diff;
    }
    printf("%lld\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
