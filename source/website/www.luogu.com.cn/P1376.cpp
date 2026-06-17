#include <bits/stdc++.h>
using namespace std;

int       n, s;
int       c[10005], y[10005];
long long ans;

void input() {
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &c[i], &y[i]);
}

void process() {
    int minCost = c[1];
    ans         = 1ll * minCost * y[1];
    for (int i = 2; i <= n; ++i) {
        if (minCost + s < c[i])
            minCost = minCost + s;
        else
            minCost = c[i];
        ans += 1ll * minCost * y[i];
    }
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
