#include <bits/stdc++.h>
using namespace std;

double x, y;

void input() { scanf("%lf", &x); }

void process() {
    if (x >= 0 && x < 5)
        y = -x + 2.5;
    else if (x >= 5 && x < 10)
        y = 2 - 1.5 * (x - 3) * (x - 3);
    else
        y = x / 2 - 1.5;
}

void output() { printf("%.3lf\n", y); }

int main() {
    input();
    process();
    output();
    return 0;
}
