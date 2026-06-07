#include <bits/stdc++.h>
using namespace std;

int  n, a[5005];
char s[100], t[100];

bool isLeap(int y) { return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); }

int daysInMonth(int m, int y) {
    if (m == 2)
        return isLeap(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    return 31;
}

long long toMin(int y, int m, int d, int h, int mi) {
    long long res = 0;
    for (int i = 0; i < y; i++)
        res += (isLeap(i) ? 366LL : 365LL) * 24 * 60;
    for (int i = 1; i < m; i++)
        res += daysInMonth(i, y) * 24LL * 60;
    res += (d - 1) * 24LL * 60;
    res += h * 60LL;
    res += mi;
    return res;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%s%s", s, t);
}

void process() {
    int y1, m1, d1, h1, mi1, y2, m2, d2, h2, mi2;
    sscanf(s, "%d-%d-%d-%d:%d", &y1, &m1, &d1, &h1, &mi1);
    sscanf(t, "%d-%d-%d-%d:%d", &y2, &m2, &d2, &h2, &mi2);
    long long total = toMin(y2, m2, d2, h2, mi2) - toMin(y1, m1, d1, h1, mi1);
    sort(a, a + n);
    int       ans  = 0;
    long long used = 0;
    for (int i = 0; i < n; i++) {
        if (used + a[i] <= total) {
            used += a[i];
            ans++;
        } else
            break;
    }
    printf("%d\n", ans);
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
