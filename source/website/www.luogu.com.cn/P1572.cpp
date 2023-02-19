#include <cstdio>
int a, b, c, d;
int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int main() {
    scanf("%d/%d", &a, &b);
    while (scanf("%d/%d", &c, &d) != EOF) {
        int m = gcd(b, d);
        a *= d / m;
        c *= b / m;
        a += c;
        b *= d / m;
        m = gcd(a, b);
        a /= m;
        b /= m;
    }
    if (b < 0) {
        a = -a;
        b = -b;
    }
    if (b == 1)
        printf("%d\n", a);
    else
        printf("%d/%d\n", a, b);
    return 0;
}