#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int d = gcd(abs(a - b), gcd(abs(a - c), abs(b - c)));
    if (d < 2) {
        printf("2\n");
        return 0;
    }
    for (int i = 2; i * i <= d; i++) {
        if (d % i == 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", d);
    return 0;
}
