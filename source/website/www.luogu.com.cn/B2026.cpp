#include <bits/stdc++.h>
using namespace std;

double a, b, r;

void input() { scanf("%lf%lf", &a, &b); }

void process() { r = fmod(a, b); }

void output() { printf("%.4lf\n", r); }

int main() {
    input();
    process();
    output();
    return 0;
}
