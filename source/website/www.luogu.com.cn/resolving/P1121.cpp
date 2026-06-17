#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, a[MAXN], f[MAXN], g[MAXN];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
}

int doQuery() {
    for (int i = 1; i <= n; ++i)
        f[i] = max(f[i - 1], 0) + a[i];
    for (int i = n; i >= 1; --i)
        g[i] = max(g[i + 1], 0) + a[i];
    for (int i = 2; i <= n; ++i)
        f[i] = max(f[i], f[i - 1]);
    for (int i = n - 1; i >= 1; --i)
        g[i] = max(g[i], g[i + 1]);
    int ans = ~0x7fffffff;
    for (int i = 1; i < n; ++i)
        ans = max(ans, f[i] + g[i + 1]);
    return ans;
}

void process() {
    int sum = 0, posCnt = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        posCnt += (a[i] >= 0);
    }
    int ans1 = doQuery();
    if (posCnt <= 1)
        printf("%d\n", ans1);
    else {
        for (int i = 1; i <= n; ++i)
            a[i] = -a[i];
        printf("%d\n", max(ans1, sum + doQuery()));
    }
}

int main() {
    input();
    process();
    return 0;
}
