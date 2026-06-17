#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll  INF  = 1e18;

struct Platform {
    int y, l, r;
} p[MAXN];

int n, H, startX, startY;
int xs[MAXN * 3], m;
int sorted[MAXN];
ll  dpL[MAXN], dpR[MAXN];
int seg[12 * MAXN], lazy[12 * MAXN];

void build(int u, int l, int r) {
    seg[u]  = 0;
    lazy[u] = -1;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void push(int u) {
    if (lazy[u] == -1)
        return;
    seg[u << 1] = seg[u << 1 | 1] = lazy[u];
    lazy[u << 1] = lazy[u << 1 | 1] = lazy[u];
    lazy[u]                         = -1;
}

void assign(int u, int l, int r, int ql, int qr, int val) {
    if (ql > r || qr < l)
        return;
    if (ql <= l && r <= qr) {
        seg[u] = lazy[u] = val;
        return;
    }
    push(u);
    int mid = (l + r) >> 1;
    assign(u << 1, l, mid, ql, qr, val);
    assign(u << 1 | 1, mid + 1, r, ql, qr, val);
}

int pointQuery(int u, int l, int r, int pos) {
    if (l == r)
        return seg[u];
    push(u);
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return pointQuery(u << 1, l, mid, pos);
    return pointQuery(u << 1 | 1, mid + 1, r, pos);
}

int comp(int x) { return lower_bound(xs, xs + m, x) - xs; }

void input() {
    scanf("%d%d", &n, &H);
    scanf("%d%d", &startX, &startY);
    m       = 0;
    xs[m++] = startX;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &p[i].y, &p[i].l, &p[i].r);
        xs[m++] = p[i].l;
        xs[m++] = p[i].r;
    }
    sort(xs, xs + m);
    m = unique(xs, xs + m) - xs;
    for (int i = 1; i <= n; i++)
        sorted[i] = i;
    sort(sorted + 1, sorted + n + 1, [&](int a, int b) { return p[a].y < p[b].y; });
}

void process() {
    build(1, 0, m - 1);
    for (int i = 1; i <= n; i++) {
        int id = sorted[i];
        int y = p[id].y, l = p[id].l, r = p[id].r;
        int cl = comp(l), cr = comp(r);

        int bl = pointQuery(1, 0, m - 1, cl);
        if (bl == 0)
            dpL[id] = (y <= H) ? y : INF;
        else if (y - p[bl].y > H)
            dpL[id] = INF;
        else {
            ll lo   = (ll)(l - p[bl].l) + dpL[bl];
            ll ro   = (ll)(p[bl].r - l) + dpR[bl];
            dpL[id] = (ll)(y - p[bl].y) + min(lo, ro);
        }

        int br = pointQuery(1, 0, m - 1, cr);
        if (br == 0)
            dpR[id] = (y <= H) ? y : INF;
        else if (y - p[br].y > H)
            dpR[id] = INF;
        else {
            ll lo   = (ll)(r - p[br].l) + dpL[br];
            ll ro   = (ll)(p[br].r - r) + dpR[br];
            dpR[id] = (ll)(y - p[br].y) + min(lo, ro);
        }

        if (cl + 1 <= cr - 1)
            assign(1, 0, m - 1, cl + 1, cr - 1, id);
    }
}

void output() {
    int bid = pointQuery(1, 0, m - 1, comp(startX));
    ll  ans;
    if (bid == 0)
        ans = (startY <= H) ? startY : INF;
    else if (startY - p[bid].y > H)
        ans = INF;
    else {
        ll lo = (ll)(startX - p[bid].l) + dpL[bid];
        ll ro = (ll)(p[bid].r - startX) + dpR[bid];
        ans   = (ll)(startY - p[bid].y) + min(lo, ro);
    }
    printf("%lld\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
