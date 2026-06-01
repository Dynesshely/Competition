#include <bits/stdc++.h>
using namespace std;
const int LEN = 500;
int a[LEN], t[LEN], r[2 * LEN];
void mul(int *x, int *y) {
    memset(r, 0, sizeof(r));
    for (int i = 0; i < LEN; ++i)
        for (int j = 0; j < LEN && i + j < LEN; ++j)
            r[i + j] += x[i] * y[j];
    memset(x, 0, sizeof(a));
    int carry = 0;
    for (int i = 0; i < LEN; ++i) {
        r[i] += carry;
        x[i] = r[i] % 10;
        carry = r[i] / 10;
    }
}
int main() {
    int P;
    scanf("%d", &P);
    int digits = (int)(P * log10(2)) + 1;
    printf("%d\n", digits);
    a[0] = 1; t[0] = 2;
    while (P > 0) {
        if (P & 1) mul(a, t);
        mul(t, t);
        P >>= 1;
    }
    a[0]--;
    int k = 0;
    for (int i = 0; i < LEN; ++i)
        if (a[i] < 0) { a[i] += 10; a[i + 1]--; } else break;
    for (int i = LEN - 1; i >= 0; --i) {
        putchar(a[i] + '0');
        if (++k % 50 == 0) putchar('\n');
    }
    return 0;
}
