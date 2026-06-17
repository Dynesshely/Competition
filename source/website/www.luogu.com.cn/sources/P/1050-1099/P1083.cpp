#include <bits/stdc++.h>
using namespace std;

int r[1000005], d[1000005], s[1000005], t[1000005];
long long diff[1000005];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &r[i]);
    for (int i = 1; i <= m; ++i) scanf("%d%d%d", &d[i], &s[i], &t[i]);
    int lo = 1, hi = m, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        for (int i = 1; i <= n + 1; ++i) diff[i] = 0;
        for (int i = 1; i <= mid; ++i) { diff[s[i]] += d[i]; diff[t[i] + 1] -= d[i]; }
        long long cur = 0; bool ok = true;
        for (int i = 1; i <= n; ++i) { cur += diff[i]; if (cur > r[i]) { ok = false; break; } }
        if (ok) lo = mid + 1;
        else { ans = mid; hi = mid - 1; }
    }
    if (ans == 0) printf("0\n");
    else printf("-1\n%d\n", ans);
    return 0;
}
