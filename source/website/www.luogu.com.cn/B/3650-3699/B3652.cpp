#include <bits/stdc++.h>
using namespace std;

int               n;
vector<long long> a;
long long         mx, mn;

int main() {
    scanf("%d", &n);
    a.resize(n);
    mx = 0;
    mn = 1e18 + 1;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        if (a[i] > mx)
            mx = a[i];
        if (a[i] < mn)
            mn = a[i];
    }
    for (int i = 0; i < n; ++i)
        printf("%lld ", mx - a[i]);
    printf("\n");
    for (int i = 0; i < n; ++i)
        printf("%lld ", a[i] - mn);
    printf("\n");
    return 0;
}
