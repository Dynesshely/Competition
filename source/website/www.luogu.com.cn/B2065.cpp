#include <bits/stdc++.h>
using namespace std;

int    n, total, eff, cTotal, cEff;
double cRate, rate;

int main() {
    scanf("%d", &n);
    scanf("%d%d", &cTotal, &cEff);
    cRate = (double)cEff / cTotal;
    for (int i = 2; i <= n; i++) {
        scanf("%d%d", &total, &eff);
        rate = (double)eff / total;
        if (rate - cRate > 0.05)
            puts("better");
        else if (cRate - rate > 0.05)
            puts("worse");
        else
            puts("same");
    }
    return 0;
}
