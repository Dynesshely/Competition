#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int         N   = 100005;
const ll          INF = 1e18;

int n;
struct Edge {
    int to, nxt;
    ll  w;
} e[N * 2];
int head[N], tot = 1;
int st[N], ins[N], fa[N], fw[N];
int cir[N], ed;
ll  pos[N], dep[N], tr[N], sum[N], sub[N], treeDiam[N];
ll  brkEdge, ans = INF;

void addEdge(int u, int v, ll w) {
    e[++tot] = {v, head[u], w};
    head[u]  = tot;
    e[++tot] = {u, head[v], w};
    head[v]  = tot;
}

void findCycle(int u, int p) {
    st[u] = ins[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == p)
            continue;
        fa[v] = u;
        fw[v] = e[i].w;
        if (!st[v])
            findCycle(v, u);
        else if (ins[v]) {
            brkEdge = e[i].w;
            ll s    = 0;
            for (int k = u; k != v; k = fa[k]) {
                pos[k] = s;
                s += fw[k];
                cir[++ed] = k;
            }
            pos[v]    = s;
            cir[++ed] = v;
        }
    }
    ins[u] = 0;
}

ll dfsDep(int u) {
    st[u] = 1;
    ll d1 = 0, d2 = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (st[v])
            continue;
        ll d = dfsDep(v) + e[i].w;
        if (d > d1) {
            d2 = d1;
            d1 = d;
        } else if (d > d2)
            d2 = d;
    }
    treeDiam[u] = d1 + d2;
    return d1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        ll  l;
        scanf("%d%d%lld", &a, &b, &l);
        addEdge(a, b, l);
    }

    findCycle(1, 0);

    memset(st, 0, sizeof st);
    for (int i = 1; i <= ed; ++i)
        st[cir[i]] = 1;

    int m       = ed;
    ll  treeAns = 0;
    for (int i = 1; i <= m; ++i) {
        int u   = cir[i];
        dep[i]  = dfsDep(u);
        sum[i]  = pos[u];
        tr[i]   = treeDiam[u];
        treeAns = max(treeAns, tr[i]);
    }

    for (int i = 1; i < m; ++i)
        sub[i] = sum[m] - sum[i];

    ll a[N], b[N], c[N], d[N];
    for (int i = 1; i < m; ++i) {
        if (i == 1)
            a[i] = dep[i];
        else
            a[i] = max(a[i - 1], dep[i] + sum[i]);
    }
    for (int i = m - 1; i >= 1; --i) {
        if (i == m - 1)
            b[i] = dep[i + 1];
        else
            b[i] = max(b[i + 1], dep[i + 1] + sub[i + 1]);
    }
    ll mn = -INF;
    for (int i = 1; i < m; ++i) {
        if (i == 1)
            c[i] = max(dep[i], tr[i]);
        else
            c[i] = max({c[i - 1], tr[i], dep[i] + sum[i] + mn});
        mn = max(mn, dep[i] - sum[i]);
    }
    mn = -INF;
    for (int i = m - 1; i >= 1; --i) {
        if (i == m - 1)
            d[i] = max(tr[i + 1], dep[i + 1]);
        else
            d[i] = max({d[i + 1], tr[i + 1], dep[i + 1] + sub[i + 1] + mn});
        mn = max(mn, dep[i + 1] - sub[i + 1]);
    }
    for (int i = 1; i < m; ++i) {
        ll cur = max({a[i], b[i], c[i], d[i], a[i] + b[i] + brkEdge});
        ans    = min(ans, cur);
    }

    ans = max(ans, treeAns);
    printf("%lld.%c\n", ans / 2, ans & 1 ? '5' : '0');
    return 0;
}
