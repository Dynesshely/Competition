#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct Cow {
    int  x, y;
    bool operator<(const Cow &o) const { return x != o.x ? x < o.x : y < o.y; }
} cows[N];

multiset<pair<long long, int>>           s;
multiset<pair<long long, int>>::iterator itPos[N];

int fa[N], sz[N];

int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

void merge(int x, int y) { fa[find(x)] = find(y); }

int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        cows[i].x = x + y;
        cows[i].y = x - y;
        fa[i]     = i;
    }
    sort(cows + 1, cows + n + 1);
    s.insert({1ll << 60, -1});
    s.insert({-(1ll << 60), -1});
    itPos[1] = s.insert({cows[1].y, 1});
    int l    = 1;
    for (int i = 2; i <= n; ++i) {
        while (cows[i].x - cows[l].x > c)
            s.erase(itPos[l++]);
        auto it = s.lower_bound({cows[i].y, -1});
        if (it->first - cows[i].y <= c)
            merge(i, it->second);
        --it;
        if (cows[i].y - it->first <= c)
            merge(i, it->second);
        itPos[i] = s.insert({cows[i].y, i});
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (find(i) == i)
            ++ans1;
        ans2 = max(ans2, ++sz[find(i)]);
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
