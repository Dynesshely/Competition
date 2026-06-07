#include <bits/stdc++.h>
using namespace std;

int n, ans;
int daysInMonth[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a[370];

int toDay(int m, int d) {
    int res = d;
    for (int i = 1; i < m; i++)
        res += daysInMonth[i];
    return res;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m, d;
        scanf("%d%d", &m, &d);
        a[i] = toDay(m, d);
    }
}

void process() {
    if (n == 0) {
        ans = 86400;
        return;
    }
    sort(a, a + n);
    int maxFree = 0;
    maxFree     = max(maxFree, a[0] - 1);
    for (int i = 1; i < n; i++)
        maxFree = max(maxFree, a[i] - a[i - 1] - 1);
    maxFree = max(maxFree, 366 - a[n - 1]);
    ans     = (int)(86400.0 * maxFree / 366.0 + 0.5);
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
