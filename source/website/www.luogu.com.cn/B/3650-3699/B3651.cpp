#include <bits/stdc++.h>
using namespace std;

int       n, k;
long long sum;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        sum += a;
        if (i == k)
            sum -= 2LL * a;
    }
    printf("%lld\n", sum);
    return 0;
}
