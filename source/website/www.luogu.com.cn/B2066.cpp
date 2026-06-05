#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    double ans = 0.0;
    for (int i = 0; i < n; ++i) {
        double x, y;
        int    p;
        scanf("%lf%lf%d", &x, &y, &p);
        double dist = sqrt(x * x + y * y);
        ans += 2.0 * dist / 50.0 + 1.5 * p;
    }
    printf("%d\n", (int)ceil(ans));
    return 0;
}
