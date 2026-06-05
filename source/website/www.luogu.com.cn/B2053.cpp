#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double d = b * b - 4 * a * c;
    if (d < 0) {
        printf("No answer!\n");
    } else if (fabs(d) < 1e-9) {
        double x = -b / (2 * a);
        printf("x1=x2=%.5lf\n", x);
    } else {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        if (x1 > x2)
            swap(x1, x2);
        printf("x1=%.5lf;x2=%.5lf\n", x1, x2);
    }
    return 0;
}
