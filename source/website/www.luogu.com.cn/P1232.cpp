#include <bits/stdc++.h>
using namespace std;

int    n, now;
double ans = 2.0;
int    dfn[200010], bfn[200010], d[200010], b[200010], c[200010];

int main() {
    scanf("%d", &n);
    c[1]++;
    c[2]--;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &dfn[i]);
        d[dfn[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &bfn[i]);
        b[bfn[i]] = i;
    }
    for (int i = 1; i < n; ++i) {
        int x = bfn[i], y = bfn[i + 1];
        if (d[x] > d[y]) {
            c[i]++;
            c[i + 1]--;
            ans++;
        }
        x = dfn[i];
        y = dfn[i + 1];
        if (!(b[x] > b[y]) && !(b[x] + 1 == b[y])) {
            c[b[x]]++;
            c[b[y]]--;
        }
    }
    for (int i = 1; i < n; ++i) {
        now += c[i];
        if (!now)
            ans += 0.5;
    }
    printf("%.3lf\n", ans);
    return 0;
}
