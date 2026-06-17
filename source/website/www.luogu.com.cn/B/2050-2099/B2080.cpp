#include <bits/stdc++.h>
using namespace std;

double x, ans, cur;
int    n, i;

void input() { scanf("%lf%d", &x, &n); }

void process() {
    ans = 1.0;
    cur = 1.0;
    for (i = 1; i <= n; i++) {
        cur *= x;
        ans += cur;
    }
}

void output() { printf("%.2lf\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
