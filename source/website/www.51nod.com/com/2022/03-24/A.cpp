#include <bits/stdc++.h>
using namespace std;
int n, k;
unsigned int s, x, a[(int)3e6 + 5];
int main() {
    scanf("%d %d %ud", &n, &k, &x);
    --k;
    for (int i = 1; i <= n; ++i) {
        a[i] = x;
        x = 1145141 * x + 1919 * (i + 1) + 810;
    }
    for (int i = 0; i <= 21; ++i) {
        if (k & (1 << i)) {
            n -= 1 << i;
            for (int j = 1; j <= n; ++j) {
                a[j] ^= a[j + (1 << i)];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        s += (long long)1 * i * (i ^ a[i]);
    }
    printf("%u\n", s);
    return 0;
}