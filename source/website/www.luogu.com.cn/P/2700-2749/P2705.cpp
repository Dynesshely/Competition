#include <bits/stdc++.h>
using namespace std;

int r, b, c, d, e, ans;

void input() { scanf("%d%d%d%d%d", &r, &b, &c, &d, &e); }

void process() {
    int base = r * c + b * d;
    int swp  = min(r, b);
    int gain = max(0, 2 * e - c - d);
    ans      = base + swp * gain;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
