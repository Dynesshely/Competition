#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int l, r;
};

int              n;
vector<Interval> row[7];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int P, t;
        scanf("%d%d", &P, &t);
        row[P].push_back({t, t + 59});
    }
}

void process() {
    int ans = 0;
    for (int p = 1; p <= 6; ++p) {
        sort(row[p].begin(), row[p].end(), [](const Interval &a, const Interval &b) { return a.r < b.r; });
        int last = -1;
        for (const auto &itv : row[p])
            if (last < itv.l) {
                ++ans;
                last = itv.r;
            }
    }
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
