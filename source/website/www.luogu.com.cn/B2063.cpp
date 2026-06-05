#include <bits/stdc++.h>
using namespace std;

int x, n;

void input() { scanf("%d%d", &x, &n); }

void process() {
    double ans = x;
    for (int i = 0; i < n; i++)
        ans *= 1.001;
    printf("%.4lf\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
