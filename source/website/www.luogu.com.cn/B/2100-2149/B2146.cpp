#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, x;
ll  h[1000005];

void input() { scanf("%d%d", &n, &x); }

void process() {
    h[0] = 1;
    if (n >= 1)
        h[1] = 2LL * x;
    for (int i = 2; i <= n; i++)
        h[i] = 2LL * x * h[i - 1] - 2LL * (i - 1) * h[i - 2];
    printf("%lld\n", h[n]);
}

int main() {
    input();
    process();
    return 0;
}
