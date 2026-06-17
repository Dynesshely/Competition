#include <bits/stdc++.h>
using namespace std;

int a, b;

void input() { scanf("%d%d", &a, &b); }

void process() {
    double res = 1.0 * a / b;
    printf("%.9lf\n", res);
}

int main() {
    input();
    process();
    return 0;
}
