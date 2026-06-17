#include <bits/stdc++.h>
using namespace std;

int    n;
double wx[25], wa1[25], wb1[25], wa2[25], wb2[25];
double ans;

struct Pt {
    double x, y;
};

double dist(const Pt &a, const Pt &b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf%lf%lf%lf", &wx[i], &wa1[i], &wb1[i], &wa2[i], &wb2[i]);
}

void process() {
    int        m = 2 + 4 * n;
    vector<Pt> p(m);
    p[0] = {0, 5};
    for (int i = 0; i < n; i++) {
        p[1 + 4 * i] = {wx[i], wa1[i]};
        p[2 + 4 * i] = {wx[i], wb1[i]};
        p[3 + 4 * i] = {wx[i], wa2[i]};
        p[4 + 4 * i] = {wx[i], wb2[i]};
    }
    p[m - 1] = {10, 5};

    const double   INF = 1e18;
    vector<double> d(m, INF);
    vector<bool>   via(m, false);
    d[0] = 0;

    for (int _ = 0; _ < m; _++) {
        int u = -1;
        for (int i = 0; i < m; i++)
            if (!via[i] && (u == -1 || d[i] < d[u]))
                u = i;
        if (u == -1)
            break;
        via[u] = true;

        for (int v = 0; v < m; v++) {
            if (via[v] || p[u].x >= p[v].x)
                continue;
            bool ok = true;
            for (int i = 0; i < n && ok; i++) {
                if (wx[i] <= p[u].x || wx[i] >= p[v].x)
                    continue;
                double y = p[u].y + (p[v].y - p[u].y) * (wx[i] - p[u].x) / (p[v].x - p[u].x);
                if ((y > 0 && y < wa1[i]) || (y > wb1[i] && y < wa2[i]) || (y > wb2[i] && y < 10))
                    ok = false;
            }
            if (ok) {
                double w = dist(p[u], p[v]);
                if (d[u] + w < d[v])
                    d[v] = d[u] + w;
            }
        }
    }
    ans = d[m - 1];
}

void output() { printf("%.2f\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
