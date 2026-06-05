#include <bits/stdc++.h>
using namespace std;

typedef long long     ll;
typedef long double   ld;
typedef pair<ld, int> pdi;

const int maxN = 5000005, maxH = 10000005, maxV = 2000000005;
const ld  eps = 1e-9;

struct line {
    int x1, y1, x2, y2;
    line(int x1 = 0, int y1 = -1, int x2 = 0, int y2 = -1)
        : x1(x1)
        , y1(y1)
        , x2(x2)
        , y2(y2) {}
    ld val(int x) const {
        if (x1 == x2)
            return x == x1 ? max(y1, y2) : -1;
        ld k = (y1 - y2) / (ld)(x1 - x2);
        ld b = y1 - k * x1;
        return k * x + b;
    }
} a[maxN];

int tot, lc[maxH], rc[maxH], bst[maxH];

ld sub(int x, int y, int p) { return a[x].val(p) - a[y].val(p); }

bool isBetter(int x, int y, int p) {
    if (!x)
        return 0;
    if (!y)
        return 1;
    return sub(x, y, p) > eps || (sub(x, y, p) > -eps && x > y);
}

void updNode(int &u, int l, int r, int x) {
    if (!u)
        u = ++tot;
    int m = (l + r) >> 1;
    if (isBetter(x, bst[u], m))
        swap(bst[u], x);
    if (isBetter(x, bst[u], l))
        updNode(lc[u], l, m, x);
    if (isBetter(x, bst[u], r))
        updNode(rc[u], m + 1, r, x);
}

void updSeg(int &u, int l, int r, int s, int t, int x) {
    if (t < l || s > r)
        return;
    if (s <= l && r <= t)
        return updNode(u, l, r, x);
    if (!u)
        u = ++tot;
    int m = (l + r) >> 1;
    updSeg(lc[u], l, m, s, t, x);
    updSeg(rc[u], m + 1, r, s, t, x);
}

pdi maxPair(pdi x, pdi y) {
    if (x.first - y.first > eps)
        return x;
    return y;
}

pdi query(int u, int l, int r, int s) {
    if (s < l || s > r || !u)
        return make_pair(-1, 0);
    pdi ret(a[bst[u]].val(s), bst[u]);
    if (l == r)
        return ret;
    int m = (l + r) >> 1;
    return maxPair(ret, maxPair(query(lc[u], l, m, s), query(rc[u], m + 1, r, s)));
}

int n, root;

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        a[i] = line(x1, y1, x2, y2);
    }
}

void process() {
    sort(a + 2, a + n + 1, [](const line &x, const line &y) { return x.x1 < y.x1; });
    int p = 2, i = 1, ans = 0;
    do {
        ans++;
        if (p <= i)
            p = i + 1;
        while (p <= n && a[i].x2 >= a[p].x1) {
            if (a[i].y2 >= a[p].val(a[i].x2))
                updSeg(root, 0, maxV, a[p].x1, a[p].x2 - 1, p);
            p++;
        }
        i = query(root, 0, maxV, a[i].x2).second;
    } while (i);
    printf("%d\n", ans);
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
