#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

int       n, m, phi[MAXN + 1];
long long ans;

void input() { scanf("%d%d", &n, &m); }

void process() {
    int lim = min(n, m);
    for (int i = 1; i <= lim; i++)
        phi[i] = i;
    for (int i = 2; i <= lim; i++)
        if (phi[i] == i)
            for (int j = i; j <= lim; j += i)
                phi[j] -= phi[j] / i;
    long long s = 0;
    for (int d = 1; d <= lim; d++)
        s += 1LL * phi[d] * (n / d) * (m / d);
    ans = 2 * s - 1LL * n * m;
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
