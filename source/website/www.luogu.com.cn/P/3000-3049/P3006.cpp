#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;

int n, m;
int fa[N], f[N], lim[N];
ll  cow[N], pass[N];

struct Query {
    ll  t, ans;
    int id;
} qs[N];

bool cmpT(Query &a, Query &b) { return a.t < b.t; }
bool cmpId(Query &a, Query &b) { return a.id < b.id; }

int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 2; i <= n; ++i) {
        scanf("%d%lld%d", &f[i], &cow[i], &lim[i]);
        pass[f[i]] -= lim[i];
        pass[i] += lim[i];
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%lld", &qs[i].t);
        qs[i].id = i;
    }
}

void process() {
    sort(qs + 1, qs + 1 + m, cmpT);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 2; i <= n; ++i)
        if (pass[i] > 0)
            pq.push({cow[i] / pass[i], i});
    int l = 1;
    while (!pq.empty() && l <= m) {
        while (l <= m && qs[l].t <= pq.top().first) {
            qs[l].ans = cow[1] - pass[1] * qs[l].t;
            ++l;
        }
        if (l > m)
            break;
        int x = pq.top().second;
        pq.pop();
        if (fa[x] != x)
            continue;
        int tp = findSet(f[x]);
        cow[tp] += cow[x];
        pass[tp] += pass[x];
        fa[x] = tp;
        if (pass[tp] > 0)
            pq.push({cow[tp] / pass[tp], tp});
    }
}

void output() {
    sort(qs + 1, qs + 1 + m, cmpId);
    for (int i = 1; i <= m; ++i)
        printf("%lld\n", qs[i].ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
