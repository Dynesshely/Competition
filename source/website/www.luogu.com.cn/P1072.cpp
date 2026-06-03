#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(int a, int b) { return (long long)a / gcd(a, b) * b; }

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a0, a1, b0, b1;
        scanf("%d%d%d%d", &a0, &a1, &b0, &b1);
        int ans = 0, sq = (int)sqrt(b1);
        for (int d = 1; d <= sq; ++d) {
            if (b1 % d == 0) {
                if (d % a1 == 0 && gcd(d / a1, a0 / a1) == 1 && lcm(d, b0) == b1) ++ans;
                int d2 = b1 / d;
                if (d2 != d && d2 % a1 == 0 && gcd(d2 / a1, a0 / a1) == 1 && lcm(d2, b0) == b1) ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
