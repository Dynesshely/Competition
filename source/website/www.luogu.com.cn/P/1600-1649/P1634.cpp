#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    scanf("%d%d", &x, &n);
    unsigned long long ans = 1;
    for (int i = 0; i < n; i++)
        ans *= (1 + x);
    printf("%llu\n", ans);
    return 0;
}
