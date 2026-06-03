#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, k;
        scanf("%lld%lld", &n, &k);
        if (k * (k + 1) / 2 <= n)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
