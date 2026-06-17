#include <bits/stdc++.h>
using namespace std;

double n;

void input() { scanf("%lf", &n); }

void process() { n = fabs(n); }

void output() { printf("%.2lf\n", n); }

int main() {
    input();
    process();
    output();
    return 0;
}
