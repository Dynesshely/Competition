#include <bits/stdc++.h>
using namespace std;

int                     n, c;
unordered_map<int, int> mp;

void input() {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mp[x]++;
    }
}

void process() {
    long long ans = 0;
    for (auto &p : mp) {
        int x = p.first;
        if (mp.find(x + c) != mp.end()) {
            ans += 1LL * mp[x] * mp[x + c];
        }
    }
    printf("%lld\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
