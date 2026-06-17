#include <bits/stdc++.h>
using namespace std;

int n, m;

void input() { scanf("%d%d", &n, &m); }

void process() {
    vector<int>           pref(m, 0);
    map<vector<int>, int> mp;
    vector<int>           key(m, 0);
    mp[key] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        for (int k = 0; k < m; k++)
            if ((x >> k) & 1)
                pref[k]++;
        for (int k = 0; k < m; k++)
            key[k] = pref[k] - pref[0];
        auto it = mp.find(key);
        if (it != mp.end())
            ans = max(ans, i - it->second);
        else
            mp[key] = i;
    }
    printf("%d\n", ans);
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
