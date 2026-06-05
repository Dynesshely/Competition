#include <bits/stdc++.h>
using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double area = fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0;
    printf("%.2lf\n", area);
    return 0;
}
