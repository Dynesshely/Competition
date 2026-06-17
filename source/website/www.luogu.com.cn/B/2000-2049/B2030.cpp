#include <bits/stdc++.h>
using namespace std;

double xa, ya, xb, yb, ans;

void input() { scanf("%lf%lf%lf%lf", &xa, &ya, &xb, &yb); }

void process() { ans = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya)); }

void output() { printf("%.3lf\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
