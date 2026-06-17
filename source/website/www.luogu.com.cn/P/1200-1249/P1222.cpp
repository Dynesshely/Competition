#include <bits/stdc++.h>
using namespace std;

struct Tri {
    int x, y, m;
};

int         n;
vector<Tri> tris, act;
vector<int> yCut;

double F(double Y) {
    double tot = 0.0, curL = -1e30, curR = -1e30;
    for (auto &t : act) {
        double l = t.x;
        double r = t.x + t.y + t.m - Y;
        if (r <= l)
            continue;
        if (l > curR) {
            if (curR > -1e29)
                tot += curR - curL;
            curL = l;
            curR = r;
        } else {
            if (r > curR)
                curR = r;
        }
    }
    if (curR > -1e29)
        tot += curR - curL;
    return tot;
}

double simpson(double L, double R) {
    double M = (L + R) * 0.5;
    return (R - L) / 6.0 * (F(L) + 4.0 * F(M) + F(R));
}

double adapt(double L, double R, double eps, double sum, int dep) {
    double M     = (L + R) * 0.5;
    double left  = simpson(L, M);
    double right = simpson(M, R);
    double diff  = left + right - sum;
    if (dep <= 0 || fabs(diff) < 15.0 * eps)
        return left + right + diff / 15.0;
    return adapt(L, M, eps * 0.5, left, dep - 1) + adapt(M, R, eps * 0.5, right, dep - 1);
}

void input() {
    scanf("%d", &n);
    tris.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &tris[i].x, &tris[i].y, &tris[i].m);
}

void process() {
    sort(tris.begin(), tris.end(), [](const Tri &a, const Tri &b) { return a.m > b.m; });
    vector<Tri> flt;
    for (auto &t : tris) {
        bool ok = true;
        for (auto &f : flt)
            if (f.x <= t.x && f.y <= t.y && f.x + f.y + f.m >= t.x + t.y + t.m) {
                ok = false;
                break;
            }
        if (ok)
            flt.push_back(t);
    }
    tris = flt;
    n    = tris.size();
    if (!n) {
        printf("0.0\n");
        return;
    }

    for (auto &t : tris) {
        yCut.push_back(t.y);
        yCut.push_back(t.y + t.m);
    }
    sort(yCut.begin(), yCut.end());
    yCut.erase(unique(yCut.begin(), yCut.end()), yCut.end());

    double ans = 0.0;
    for (int i = 0; i + 1 < (int)yCut.size(); i++) {
        int L = yCut[i], R = yCut[i + 1];
        act.clear();
        for (auto &t : tris)
            if (t.y <= L && t.y + t.m >= R)
                act.push_back(t);
        if (act.empty())
            continue;
        sort(act.begin(), act.end(), [](const Tri &a, const Tri &b) { return a.x < b.x; });
        ans += adapt(L, R, 1e-8, simpson(L, R), 20);
    }
    printf("%.1f\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
