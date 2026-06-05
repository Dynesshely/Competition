#include <bits/stdc++.h>
using namespace std;

int x, a, y, b;

void input() { scanf("%d%d%d%d", &x, &a, &y, &b); }

void output() {
    double z = (double)(y * b - x * a) / (b - a);
    printf("%.2lf\n", z);
}

int main() {
    input();
    output();
    return 0;
}
