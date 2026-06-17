#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, m, ans;
int l[N], r[N], f[N], q[N], hd, bk, j;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n + 1; ++i)
        r[i] = i - 1;
    for (int k = 0; k < m; ++k) {
        int x, y;
        scanf("%d%d", &x, &y);
        r[y]     = min(r[y], x - 1);
        l[y + 1] = max(l[y + 1], x);
    }
}

void process() {
    for (int i = n; i; --i)
        r[i] = min(r[i], r[i + 1]);
    for (int i = 1; i <= n; ++i)
        l[i] = max(l[i], l[i - 1]);
    hd = 0, bk = 1, j = 1;
    f[0] = 0, q[0] = 0;
    for (int i = 1; i <= n + 1; ++i) {
        for (; j <= n && j <= r[i]; ++j)
            if (f[j] != -1) {
                for (; hd < bk && f[j] > f[q[bk - 1]]; --bk)
                    ;
                q[bk++] = j;
            }
        for (; hd < bk && q[hd] < l[i]; ++hd)
            ;
        f[i] = hd < bk ? f[q[hd]] + 1 : -1;
        if (f[i] != -1)
            ans = max(ans, f[i]);
    }
}

void output() { printf("%d\n", f[n + 1] != -1 ? f[n + 1] - 1 : -1); }

int main() {
    input();
    process();
    output();
    return 0;
}
