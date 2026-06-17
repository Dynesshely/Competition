#include <bits/stdc++.h>
using namespace std;

int                    n;
vector<pair<int, int>> events;
multiset<int>          ms;
vector<pair<int, int>> ans;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int h, l, r;
        scanf("%d%d%d", &h, &l, &r);
        events.push_back({l, -h});
        events.push_back({r, h});
    }
}

void process() {
    sort(events.begin(), events.end());
    ms.insert(0);
    int prevTop = 0;
    for (auto &e : events) {
        int x = e.first, h = e.second;
        if (h < 0)
            ms.insert(-h);
        else
            ms.erase(ms.find(h));
        int curTop = *ms.rbegin();
        if (curTop != prevTop) {
            ans.push_back({x, prevTop});
            ans.push_back({x, curTop});
            prevTop = curTop;
        }
    }
}

void output() {
    printf("%d\n", (int)ans.size());
    for (auto &p : ans)
        printf("%d %d\n", p.first, p.second);
}

int main() {
    input();
    process();
    output();
    return 0;
}
