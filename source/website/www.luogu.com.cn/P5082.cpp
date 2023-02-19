#include <bits/stdc++.h>

using namespace std;

int n, tmp;

long long sum_per_sub_max = 0, sum_per_sub_real = 0;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        sum_per_sub_max += tmp;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        sum_per_sub_real += tmp;
    }
    printf("%0.6f\n", ((double)sum_per_sub_max * 3 - (double)sum_per_sub_real * 2) /
                          (double)(sum_per_sub_max - sum_per_sub_real));
    return 0;
}