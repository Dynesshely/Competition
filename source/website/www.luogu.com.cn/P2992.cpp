#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Pt { ll x, y; int q; };
int main() {
    int n; scanf("%d", &n);
    vector<Pt> pts(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &pts[i].x, &pts[i].y);
        pts[i].q = (pts[i].y > 0 || (pts[i].y == 0 && pts[i].x > 0)) ? 0 : 1;
    }
    sort(pts.begin(), pts.end(), [](auto &a, auto &b) {
        int qa = a.q, qb = b.q;
        if (qa != qb) return qa < qb;
        return a.x * b.y - a.y * b.x > 0;
    });
    auto same = [](auto &a, auto &b) { return a.x * b.y == a.y * b.x && a.q == b.q; };
    vector<Pt> uniq;
    for (int i = 0; i < n; ++i) {
        if (uniq.empty() || !same(uniq.back(), pts[i])) uniq.push_back(pts[i]);
    }
    int m = uniq.size();
    if (m < 3) { printf("0\n"); return 0; }
    vector<Pt> all(2 * m);
    for (int i = 0; i < m; ++i) all[i] = all[i + m] = uniq[i];
    ll total = (ll)n * (n - 1) * (n - 2) / 6;
    int r = 0;
    for (int l = 0; l < m; ++l) {
        if (r < l) r = l;
        while (r + 1 < l + m && all[l].x * all[r + 1].y - all[l].y * all[r + 1].x > 0) r++;
        int cnt = r - l;
        total -= (ll)cnt * (cnt - 1) / 2;
    }
    printf("%lld\n", total);
    return 0;
}
