#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 9;

struct Rect {
    long long w, l;
} a[N];

int       n, q[N], hd, tl;
long long f[N];

double slope(int j1, int j2) { return (double)(f[j1] - f[j2]) / (double)(a[j2 + 1].w - a[j1 + 1].w); }

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &a[i].w, &a[i].l);
    sort(a + 1, a + n + 1, [](const Rect &x, const Rect &y) {
        if (x.w != y.w)
            return x.w > y.w;
        return x.l > y.l;
    });
    int m = 1;
    for (int i = 2; i <= n; ++i)
        if (a[m].l < a[i].l)
            a[++m] = a[i];
    for (int i = 1; i <= m; ++i) {
        while (hd < tl && slope(q[hd], q[hd + 1]) <= a[i].l)
            ++hd;
        f[i] = f[q[hd]] + a[i].l * a[q[hd] + 1].w;
        while (hd < tl && slope(q[tl], i) <= slope(q[tl - 1], q[tl]))
            --tl;
        q[++tl] = i;
    }
    printf("%lld\n", f[m]);
    return 0;
}
