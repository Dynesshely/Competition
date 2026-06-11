#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
int       n, h[MAXN], l[MAXN], r[MAXN], ans;

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
}

void process() {
    l[0] = 0;
    for (int i = 1; i <= n; i++)
        l[i] = max(l[i - 1], h[i]);
    r[n + 1] = 0;
    for (int i = n; i >= 1; i--)
        r[i] = max(r[i + 1], h[i]);
    for (int i = 1; i <= n; i++)
        ans += min(l[i], r[i]) - h[i];
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
