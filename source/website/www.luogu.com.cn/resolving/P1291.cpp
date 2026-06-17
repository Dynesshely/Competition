#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b           = a % b;
        a           = t;
    }
    return a;
}

int digitCount(long long x) {
    if (x == 0)
        return 1;
    int r = 0;
    while (x) {
        r++;
        x /= 10;
    }
    return r;
}

int main() {
    int n;
    scanf("%d", &n);
    long long num = 0, den = 1;
    for (int i = 1; i <= n; i++) {
        num         = num * i + (long long)n * den;
        den         = den * i;
        long long g = gcd(num, den);
        num /= g;
        den /= g;
    }
    if (den == 1) {
        printf("%lld\n", num);
    } else {
        long long intPart = num / den;
        long long rem     = num % den;
        int       dDen    = digitCount(den);
        int       dInt    = digitCount(intPart);
        int       w       = dInt + dDen;
        printf("%*lld\n", w, rem);
        printf("%lld", intPart);
        for (int i = 0; i < dDen; i++)
            printf("-");
        printf("\n");
        printf("%*lld\n", w, den);
    }
    return 0;
}
