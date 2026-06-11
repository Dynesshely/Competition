#include <bits/stdc++.h>
using namespace std;

double s, a, b, ans;

void input() { scanf("%lf%lf%lf", &s, &a, &b); }

void process() {
    if (s == 0)
        ans = 0;
    else if (b == 0)
        ans = s / a;
    else
        ans = s * (a + 3 * b) / (b * (b + 3 * a));
}

void output() { printf("%.6lf\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
