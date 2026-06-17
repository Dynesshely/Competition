#include <bits/stdc++.h>
using namespace std;

int main() {
    double r;
    scanf("%lf", &r);
    double pi = 3.14159;
    double d  = 2 * r;
    double c  = 2 * pi * r;
    double s  = pi * r * r;
    printf("%.4lf %.4lf %.4lf\n", d, c, s);
    return 0;
}
