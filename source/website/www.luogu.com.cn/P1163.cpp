#include <bits/stdc++.h>
using namespace std;

double w0, w;
int    m;

void input() { scanf("%lf%lf%d", &w0, &w, &m); }

void process() {
    if (w * m <= w0 + 1e-12) {
        printf("0.0");
        return;
    }
    double lo = 0, hi = 3.0;
    for (int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        double pm  = exp(-m * log(1 + mid));
        double pv  = w * (1 - pm) / mid;
        if (pv > w0)
            lo = mid;
        else
            hi = mid;
    }
    printf("%.1f", (lo + hi) / 2 * 100);
}

int main() {
    input();
    process();
    return 0;
}
