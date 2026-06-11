#include <bits/stdc++.h>
using namespace std;

struct Rect {
    int    x, y, l;
    double lAng, rAng, eqAng;
};

double dist(const Rect &r, double ang) {
    if (ang < r.eqAng)
        return r.y / sin(ang);
    else
        return r.x / cos(ang);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<Rect> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].l);
        a[i].lAng  = atan2(a[i].y, a[i].x + a[i].l);
        a[i].rAng  = atan2(a[i].y + a[i].l, a[i].x);
        a[i].eqAng = atan2(a[i].y, a[i].x);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<pair<double, double>> blocked;
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            double L = max(a[i].lAng, a[j].lAng);
            double R = min(a[i].rAng, a[j].rAng);
            if (L >= R)
                continue;
            double pts[6] = {L, R, atan2(a[j].y, a[i].x), atan2(a[i].y, a[j].x), a[i].eqAng, a[j].eqAng};
            sort(pts, pts + 6);
            for (int k = 0; k + 1 < 6; k++) {
                double l = max(pts[k], L), r = min(pts[k + 1], R);
                if (r - l < 1e-12)
                    continue;
                double mid = (l + r) * 0.5;
                if (dist(a[j], mid) < dist(a[i], mid))
                    blocked.push_back({l, r});
            }
        }
        sort(blocked.begin(), blocked.end());
        double cur = a[i].lAng;
        bool   vis = false;
        for (auto &b : blocked) {
            if (b.first > cur + 1e-12) {
                vis = true;
                break;
            }
            if (b.second > cur)
                cur = b.second;
        }
        if (!vis && cur < a[i].rAng - 1e-12)
            vis = true;
        if (vis)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
