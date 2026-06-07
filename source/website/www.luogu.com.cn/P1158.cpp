#include <bits/stdc++.h>
using namespace std;

struct Missile {
    int d1, d2;
};

int             n, xa, ya, xb, yb, ans;
vector<Missile> m;

void input() {
    scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
    scanf("%d", &n);
    m.resize(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        m[i].d1 = (x - xa) * (x - xa) + (y - ya) * (y - ya);
        m[i].d2 = (x - xb) * (x - xb) + (y - yb) * (y - yb);
    }
}

void process() {
    sort(m.begin(), m.end(), [](const Missile &a, const Missile &b) { return a.d1 < b.d1; });
    vector<int> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; --i)
        suf[i] = max(suf[i + 1], m[i].d2);
    ans = INT_MAX;
    for (int i = 0; i <= n; ++i) {
        int r1 = i == 0 ? 0 : m[i - 1].d1;
        ans    = min(ans, r1 + suf[i]);
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
