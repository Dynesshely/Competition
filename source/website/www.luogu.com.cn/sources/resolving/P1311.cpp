#include <bits/stdc++.h>
using namespace std;

int       n, k, p;
int       cnt[55], valid[55];
long long ans;

void input() { scanf("%d%d%d", &n, &k, &p); }

void process() {
    for (int i = 1; i <= n; ++i) {
        int color, cost;
        scanf("%d%d", &color, &cost);
        if (cost <= p)
            for (int j = 0; j < k; ++j)
                valid[j] = cnt[j];
        ans += valid[color];
        ++cnt[color];
    }
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
