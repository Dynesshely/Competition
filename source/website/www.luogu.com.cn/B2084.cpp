#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            printf("%lld\n", n / i);
            return 0;
        }
    return 0;
}
