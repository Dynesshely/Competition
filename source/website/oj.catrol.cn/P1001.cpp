#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a, b, tmp;
    scanf("%lld %lld", &a, &b);
    tmp = a, a = b, b = tmp;
    printf("%lld %lld\n", a + b, a - b);
    return 0;
}