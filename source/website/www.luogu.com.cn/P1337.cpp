#include <bits/stdc++.h>
using namespace std;

int    n;
double xs[1005], ys[1005], wt[1005];
double ax, ay;

double calc(double x, double y) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        double dx = x - xs[i], dy = y - ys[i];
        res += sqrt(dx * dx + dy * dy) * wt[i];
    }
    return res;
}

void input() {
    scanf("%d", &n);
    double sumw = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf%lf", &xs[i], &ys[i], &wt[i]);
        ax += xs[i] * wt[i];
        ay += ys[i] * wt[i];
        sumw += wt[i];
    }
    ax /= sumw;
    ay /= sumw;
}

void process() {
    double ae = calc(ax, ay);
    for (int run = 0; run < 4; run++) {
        double t = 10000, cx = ax, cy = ay, ce = ae;
        while (t > 1e-14) {
            double nx    = cx + t * (rand() * 2.0 / RAND_MAX - 1);
            double ny    = cy + t * (rand() * 2.0 / RAND_MAX - 1);
            double ne    = calc(nx, ny);
            double delta = ne - ce;
            if (delta < 0) {
                cx = nx;
                cy = ny;
                ce = ne;
            } else if (exp(-delta / t) * RAND_MAX > rand()) {
                cx = nx;
                cy = ny;
                ce = ne;
            }
            if (ne < ae) {
                ax = nx;
                ay = ny;
                ae = ne;
            }
            t *= 0.999;
        }
    }
    for (int i = 0; i < 100000; i++) {
        double nx = 0, ny = 0, sumw = 0;
        for (int j = 0; j < n; j++) {
            double d = sqrt((ax - xs[j]) * (ax - xs[j]) + (ay - ys[j]) * (ay - ys[j]));
            if (d < 1e-12) {
                nx   = ax;
                ny   = ay;
                sumw = 1;
                break;
            }
            double w = wt[j] / d;
            nx += xs[j] * w;
            ny += ys[j] * w;
            sumw += w;
        }
        double px = nx / sumw, py = ny / sumw;
        if (fabs(px - ax) < 1e-12 && fabs(py - ay) < 1e-12)
            break;
        ax = px;
        ay = py;
    }
}

void output() { printf("%.3lf %.3lf\n", ax, ay); }

int main() {
    srand(time(0));
    input();
    process();
    output();
    return 0;
}
