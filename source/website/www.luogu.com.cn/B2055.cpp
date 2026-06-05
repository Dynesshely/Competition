#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        double x;
        scanf("%lf", &x);
        sum += x;
    }
    double avg = sum / n;
    printf("%.4f\n", avg);
    return 0;
}
