#include <bits/stdc++.h>
using namespace std;

int    n, S, T;
double a[100010];
double p[100010];
int    q[100010];

bool check(double x) {
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i] - x;
    int h = 0, t = -1;
    for (int i = S; i <= n; i++) {
        int pos = i - S;
        while (h <= t && p[q[t]] >= p[pos])
            t--;
        q[++t] = pos;
        while (h <= t && q[h] < i - T)
            h++;
        if (h <= t && p[i] - p[q[h]] >= 0)
            return true;
    }
    return false;
}

void input() {
    scanf("%d", &n);
    scanf("%d%d", &S, &T);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &a[i]);
}

void process() {
    double l = -1e4, r = 1e4;
    for (int i = 0; i < 50; i++) {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.3lf\n", l);
}

int main() {
    input();
    process();
    return 0;
}
