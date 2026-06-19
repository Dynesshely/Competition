#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        s += i;
        printf("%lld\n", s);
    }
    return 0;
}
