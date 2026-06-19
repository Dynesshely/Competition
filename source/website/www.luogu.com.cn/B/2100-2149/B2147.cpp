#include <bits/stdc++.h>
using namespace std;

double x;
int    n;

double doSolve(double x, int n) {
    if (n == 1)
        return sqrt(1 + x);
    return sqrt(n + doSolve(x, n - 1));
}

void input() { scanf("%lf%d", &x, &n); }

void process() { printf("%.2f\n", doSolve(x, n)); }

int main() {
    input();
    process();
    return 0;
}
