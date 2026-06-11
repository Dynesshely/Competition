#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;
vector<int>                deg, fa, sz;
int                        n;
bool                       ans;

int find(int x) {
    while (fa[x] != x) {
        fa[x] = fa[fa[x]];
        x     = fa[x];
    }
    return x;
}

void input() {
    char a[15], b[15];
    n = 0;
    while (scanf("%s %s", a, b) == 2) {
        string sa(a), sb(b);
        if (!mp.count(sa)) {
            mp[sa] = n++;
            deg.push_back(0);
            fa.push_back(n - 1);
            sz.push_back(1);
        }
        if (!mp.count(sb)) {
            mp[sb] = n++;
            deg.push_back(0);
            fa.push_back(n - 1);
            sz.push_back(1);
        }
        int u = mp[sa], v = mp[sb];
        deg[u]++;
        deg[v]++;
        int fu = find(u), fv = find(v);
        if (fu != fv) {
            if (sz[fu] < sz[fv])
                swap(fu, fv);
            fa[fv] = fu;
            sz[fu] += sz[fv];
        }
    }
}

void process() {
    if (!n) {
        ans = true;
        return;
    }
    int odd = 0;
    for (int i = 0; i < n; i++)
        if (deg[i] & 1)
            odd++;
    if (odd != 0 && odd != 2) {
        ans = false;
        return;
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (!deg[i])
            continue;
        int fi = find(i);
        if (root == -1)
            root = fi;
        else if (fi != root) {
            ans = false;
            return;
        }
    }
    ans = true;
}

void output() { printf("%s\n", ans ? "Possible" : "Impossible"); }

int main() {
    input();
    process();
    output();
    return 0;
}
