#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    long long sq = (long long)sqrt(n);
    for (long long i = 1; i <= sq; ++i)
        printf("%lld ", i * i);
    return 0;
}
