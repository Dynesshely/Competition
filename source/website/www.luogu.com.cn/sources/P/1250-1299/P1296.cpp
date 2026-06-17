#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int       n, d, p[MAXN];
long long ans;

void input() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
}

void process() {
    sort(p, p + n);
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && p[j] - p[i] <= d)
            j++;
        ans += j - i - 1;
    }
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
