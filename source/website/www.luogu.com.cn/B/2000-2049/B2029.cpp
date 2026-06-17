#include <bits/stdc++.h>
using namespace std;

int h, r, ans;

void input() { scanf("%d%d", &h, &r); }

void process() {
    int den = 314 * r * r * h;
    ans     = (2000000 + den - 1) / den;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
