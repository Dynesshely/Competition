#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, n, m, x;
    scanf("%d%d%d%d", &a, &n, &m, &x);
    int F[22] = {};
    F[0] = 0; F[1] = 1;
    for (int i = 2; i <= n; ++i) F[i] = F[i - 1] + F[i - 2];
    if (n == 1) { printf("%d\n", a); return 0; }
    if (n == 2) {
        if (x == 1) printf("%d\n", a);
        else printf("0\n");
        return 0;
    }
    if (n == 3) {
        int u = m - a;
        if (x == 1) printf("%d\n", a);
        else if (x == 2) printf("%d\n", a);
        else printf("%d\n", a + u);
        return 0;
    }
    int f_n2 = F[n - 2];
    int f_n3 = F[n - 3];
    int num = m - a * (1 + f_n3);
    int den = f_n2 - 1;
    if (den == 0 || num % den != 0) { printf("0\n"); return 0; }
    int u = num / den;
    int ans;
    if (x == 1) ans = a;
    else if (x == 2) ans = a;
    else {
        int f_x2 = F[x - 2];
        int f_x1 = F[x - 1];
        ans = a * (1 + f_x2) + u * (f_x1 - 1);
    }
    printf("%d\n", ans);
    return 0;
}
