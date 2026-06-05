#include <bits/stdc++.h>
using namespace std;

double f;

void input() { scanf("%lf", &f); }

void process() { f = 5 * (f - 32) / 9; }

void output() { printf("%.5lf\n", f); }

int main() {
    input();
    process();
    output();
    return 0;
}
