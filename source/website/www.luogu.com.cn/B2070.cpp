#include <bits/stdc++.h>
using namespace std;

int    n;
double ans;

void input() { scanf("%d", &n); }

void process() {
    ans = 0.0;
    for (int i = 1; i <= n; i++)
        if (i % 2 == 1)
            ans += 1.0 / i;
        else
            ans -= 1.0 / i;
}

void output() { printf("%.4lf\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
