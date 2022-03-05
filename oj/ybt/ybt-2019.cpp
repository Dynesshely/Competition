#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, ans = 1, i = 1; scanf("%lld", &n);
    for(; i <= n; ++ i) ans = ans * i;
    printf("%lld\n", ans);
    return 0;
}