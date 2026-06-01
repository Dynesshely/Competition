#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    scanf("%d", &n);
    ll C = 1;
    for (int i = 1; i <= n; ++i)
        C = C * (4 * i - 2) / (i + 1);
    printf("%lld\n", C);
    return 0;
}
