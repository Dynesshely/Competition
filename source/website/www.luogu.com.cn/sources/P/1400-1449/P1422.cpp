#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    double ans;
    if (n <= 150) {
        ans = n * 0.4463;
    } else if (n <= 400) {
        ans = 150 * 0.4463 + (n - 150) * 0.4663;
    } else {
        ans = 150 * 0.4463 + 250 * 0.4663 + (n - 400) * 0.5663;
    }
    printf("%.1f\n", ans);
    return 0;
}
