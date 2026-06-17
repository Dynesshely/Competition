#include <bits/stdc++.h>
using namespace std;

int    n;
double e;

void input() { scanf("%d", &n); }

void process() {
    e           = 1.0;
    double term = 1.0;
    for (int i = 1; i <= n; ++i) {
        term /= i;
        e += term;
    }
}

void output() { printf("%.10lf\n", e); }

int main() {
    input();
    process();
    output();
    return 0;
}
