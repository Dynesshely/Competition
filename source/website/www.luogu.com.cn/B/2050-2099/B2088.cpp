#include <bits/stdc++.h>
using namespace std;

int main() {
    int    cnt;
    double tot   = 0;
    double p[10] = {28.9, 32.7, 45.6, 78.0, 35.0, 86.2, 27.8, 43.0, 56.0, 65.0};
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &cnt);
        tot += cnt * p[i];
    }
    printf("%.1lf\n", tot);
    return 0;
}
