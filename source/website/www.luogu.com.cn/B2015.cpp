#include <bits/stdc++.h>
using namespace std;

int main() {
    double r1, r2;
    scanf("%lf%lf", &r1, &r2);
    double r = 1.0 / (1.0 / r1 + 1.0 / r2);
    printf("%.2lf\n", r);
    return 0;
}
