#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000100;
int n, a[maxn], b[maxn];
long long ans = 0;
int main(){
    freopen("hard.in", "r", stdin);
    freopen("hard.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++ i)
        scanf("%d", &b[i]);
    for(int i = 1; i <= n; ++ i){
        long long term = 0;
        for(int j = 1; j <= n; ++ j)
            term += (long long)(sqrt(abs(a[i] - a[j])));
        ans += term;
    }
    printf("%lld\n", ans);
    return 0;
}
