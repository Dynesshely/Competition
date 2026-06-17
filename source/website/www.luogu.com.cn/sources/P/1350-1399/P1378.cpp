#include <bits/stdc++.h>
using namespace std;

int    n;
double px[10], py[10];
double lx, ly, rx, ry;
double ans;

double dist(int a, int b) { return sqrt((px[a] - px[b]) * (px[a] - px[b]) + (py[a] - py[b]) * (py[a] - py[b])); }

void input() {
    double x1, y1, x2, y2;
    scanf("%d", &n);
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    lx = min(x1, x2);
    rx = max(x1, x2);
    ly = min(y1, y2);
    ry = max(y1, y2);
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &px[i], &py[i]);
}

void process() {
    double boxArea = (rx - lx) * (ry - ly);
    int    ord[10];
    for (int i = 0; i < n; i++)
        ord[i] = i;
    double maxOil = 0;
    do {
        double r[10] = {0};
        double cur   = 0;
        for (int i = 0; i < n; i++) {
            int    p   = ord[i];
            double lim = min(min(px[p] - lx, rx - px[p]), min(py[p] - ly, ry - py[p]));
            for (int j = 0; j < i; j++) {
                int    q = ord[j];
                double d = dist(p, q) - r[q];
                if (d < 0)
                    d = 0;
                if (d < lim)
                    lim = d;
            }
            r[p] = lim;
            cur += acos(-1.0) * lim * lim;
        }
        if (cur > maxOil)
            maxOil = cur;
    } while (next_permutation(ord, ord + n));
    ans = boxArea - maxOil;
}

void output() { printf("%.0f\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
