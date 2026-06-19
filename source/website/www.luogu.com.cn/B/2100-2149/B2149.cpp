#include <bits/stdc++.h>
using namespace std;

double a, b, c;

bool isTriangle(double a, double b, double c) { return a + b > c && a + c > b && b + c > a; }

double calcArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void input() { scanf("%lf%lf%lf", &a, &b, &c); }

void process() {
    if (isTriangle(a, b, c))
        printf("%.2f\n", calcArea(a, b, c));
    else
        printf("No solution.\n");
}

int main() {
    input();
    process();
    return 0;
}
