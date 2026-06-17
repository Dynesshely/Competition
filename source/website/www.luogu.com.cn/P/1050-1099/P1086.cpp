#include <bits/stdc++.h>
using namespace std;

struct Peanut { int r, c, val; } p[405];

int main() {
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    int cnt = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            int x; scanf("%d", &x);
            if (x > 0) { p[cnt].r = i; p[cnt].c = j; p[cnt].val = x; ++cnt; }
        }
    sort(p, p + cnt, [](const Peanut &a, const Peanut &b) { return a.val > b.val; });
    int ans = 0, t = 0, cr = 0, cc = 0;
    for (int i = 0; i < cnt; ++i) {
        int dist = (cr == 0) ? p[i].r : abs(p[i].r - cr) + abs(p[i].c - cc);
        if (t + dist + 1 + p[i].r <= k) { t += dist + 1; ans += p[i].val; cr = p[i].r; cc = p[i].c; }
        else break;
    }
    printf("%d\n", ans);
    return 0;
}
