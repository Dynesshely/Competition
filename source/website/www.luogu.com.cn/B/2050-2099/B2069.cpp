#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

void process() {
    double ans = 0;
    int    p = 1, q = 2;
    for (int i = 0; i < n; i++) {
        ans += 1.0 * q / p;
        int t = q;
        q     = q + p;
        p     = t;
    }
    printf("%.4lf\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
