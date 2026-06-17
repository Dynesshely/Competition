#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N   = 50005;
const ll  INF = 4e18;

struct Edge {
    int v;
    ll  w;
};

struct Node {
    int id, d;
    ll  s;
};

int n, rt, tot;
ll  k, ans;

vector<Edge> g[N];
Node         p[N];

int  sz[N], mx[N];
bool vis[N];

pair<ll, int> mn[2];

void input();
void process();
void output();

void        getrt(int, int, int);
void        getdis(int, int, int, int, ll);
bool        check(ll);
void        solve(int);
inline void ins(pair<ll, int>);

int main() {
    input();
    process();
    output();
    return 0;
}

void input() {
    scanf("%d%lld", &n, &k);

    for (int i = 1; i < n; i++) {
        int u, v;
        ll  w;

        scanf("%d%d%lld", &u, &v, &w);
        w -= k;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}

void process() {
    ans = (ll)1e13;

    rt = 0;
    getrt(1, 0, n);

    solve(rt);
}

void output() { printf("%lld\n", ans); }

inline void ins(pair<ll, int> x) {
    if (x.first < mn[0].first) {
        if (mn[0].second != x.second)
            mn[1] = mn[0];
        mn[0] = x;
    } else if (x.first < mn[1].first && mn[0].second != x.second)
        mn[1] = x;
}

void getrt(int u, int fa, int all) {
    sz[u] = 1;
    mx[u] = 0;

    for (auto e : g[u]) {
        int v = e.v;

        if (v == fa || vis[v])
            continue;

        getrt(v, u, all);

        sz[u] += sz[v];
        mx[u] = max(mx[u], sz[v]);
    }

    mx[u] = max(mx[u], all - sz[u]);

    if (!rt || mx[u] < mx[rt])
        rt = u;
}

void getdis(int u, int fa, int id, int dep, ll sum) {
    p[++tot] = {id, dep, sum};

    for (auto e : g[u]) {
        int v = e.v;

        if (v == fa || vis[v])
            continue;

        getdis(v, u, id, dep + 1, sum + e.w);
    }
}

bool check(ll x) {
    mn[0] = mn[1] = {INF, 0};

    for (int i = 1, j = tot; i <= tot; i++) {
        while (j >= 1 && p[i].s + p[j].s >= 0) {
            ins({p[j].s - x * p[j].d, p[j].id});
            --j;
        }

        ll t = (p[i].id != mn[0].second ? mn[0].first : mn[1].first);

        if (x * p[i].d - p[i].s > t)
            return 1;
    }

    mn[0] = mn[1] = {INF, 0};

    for (int i = tot, j = 1; i >= 1; i--) {
        while (j <= tot && p[i].s + p[j].s < 0) {
            ins({-p[j].s - x * p[j].d, p[j].id});
            ++j;
        }

        ll t = (p[i].id != mn[0].second ? mn[0].first : mn[1].first);

        if (p[i].s + x * p[i].d > t)
            return 1;
    }

    return 0;
}

void solve(int u) {
    tot  = 1;
    p[1] = {u, 0, 0};

    for (auto e : g[u]) {
        int v = e.v;

        if (vis[v])
            continue;

        getdis(v, u, v, 1, e.w);
    }

    sort(p + 1, p + tot + 1, [&](const Node &a, const Node &b) { return a.s < b.s; });

    ll l = 1, r = ans;

    while (l <= r) {
        ll mid = (l + r) >> 1;

        if (check(mid)) {
            ans = mid - 1;
            r   = mid - 1;
        } else
            l = mid + 1;
    }

    vis[u] = 1;

    for (auto e : g[u]) {
        int v = e.v;

        if (vis[v])
            continue;

        rt = 0;
        getrt(v, u, sz[v]);

        solve(rt);
    }
}