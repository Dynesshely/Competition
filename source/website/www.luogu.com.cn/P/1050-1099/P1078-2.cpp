#include <bits/stdc++.h>
using namespace std;

long long reject[105][105];

struct Country {
    long long                          cult;
    vector<pair<long long, long long>> nbr;
} cty[105];

long long n, k, m, s, t;

struct Entry {
    long long      node;
    long long      dist;
    set<long long> learned;
    Entry() {
        node = -1;
        dist = 0;
    }
    Entry(long long nd, long long d, long long init) {
        node = nd;
        dist = d;
        learned.insert(init);
    }
    bool operator<(const Entry &o) const { return dist >= o.dist; }
};

priority_queue<Entry> pq;

bool blocked(const set<long long> &learned, long long tc) {
    for (long long i = 1; i <= k; ++i)
        if (reject[tc][i] && learned.count(i))
            return true;
    return false;
}

long long search() {
    long long cnt = 0;
    pq.push(Entry(s, 0, cty[s].cult));
    while (!pq.empty()) {
        Country &cur = cty[pq.top().node];
        Entry    ent = pq.top();
        ++cnt;
        if (cnt > 800)
            return -1;
        if (ent.node == t)
            return ent.dist;
        pq.pop();
        for (long long i = 0; i < (long long)cur.nbr.size(); ++i) {
            Entry nxt = ent;
            nxt.dist += cur.nbr[i].second;
            nxt.node = cur.nbr[i].first;
            if (blocked(ent.learned, cty[nxt.node].cult))
                continue;
            nxt.learned.insert(cty[nxt.node].cult);
            pq.push(nxt);
        }
    }
    return -1;
}

int main() {
    scanf("%lld%lld%lld%lld%lld", &n, &k, &m, &s, &t);
    for (long long i = 1; i <= n; ++i)
        scanf("%lld", &cty[i].cult);
    for (long long i = 1; i <= k; ++i) {
        for (long long j = 1; j <= k; ++j) {
            scanf("%lld", &reject[i][j]);
            if (i == j)
                reject[i][j] = 1;
        }
    }
    for (long long i = 1; i <= m; ++i) {
        long long u, v, d;
        scanf("%lld%lld%lld", &u, &v, &d);
        cty[u].nbr.push_back({v, d});
        cty[v].nbr.push_back({u, d});
    }
    printf("%lld\n", search());
    return 0;
}
