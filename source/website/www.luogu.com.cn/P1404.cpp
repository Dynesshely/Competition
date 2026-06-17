#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int       a[MAXN], n, m;
long long ps[MAXN];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
}

bool check(int v) {
    ps[0] = 0;
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + 1000LL * a[i] - v;
    long long minPs = 0;
    for (int i = m; i <= n; i++) {
        if (ps[i] >= minPs)
            return true;
        if (ps[i - m + 1] < minPs)
            minPs = ps[i - m + 1];
    }
    return false;
}

void process() {
    int l = 0, r = 2000 * 1000;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", l);
}

int main() {
    input();
    process();
    return 0;
}
