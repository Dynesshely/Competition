#include <bits/stdc++.h>
using namespace std;

int a, b, n;

int main() {
    scanf("%d%d%d", &a, &b, &n);
    int r = a % b;
    for (int i = 1; i <= n; i++) {
        r *= 10;
        int d = r / b;
        r %= b;
        if (i == n) {
            printf("%d\n", d);
            return 0;
        }
    }
}
