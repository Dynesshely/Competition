#include <bits/stdc++.h>
using namespace std;
int main() {
    double s, x;
    scanf("%lf%lf", &s, &x);
    double l = s - x, r = s + x;
    double p = 0, d = 7;
    if (p >= l) {
        p += d;
        printf(p > r ? "n\n" : "y\n");
        return 0;
    }
    while (p < l) {
        p += d;
        if (p < l)
            d *= 0.98;
    }
    if (p > r) {
        printf("n\n");
    } else {
        d *= 0.98;
        p += d;
        printf(p > r ? "n\n" : "y\n");
    }
    return 0;
}
