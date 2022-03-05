#include <bits/stdc++.h>
using namespace std;
int n, maxn = 0, tmp;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){ scanf("%d", &tmp); maxn = max(maxn, tmp); }
    printf("%d\n", maxn);
    return 0;
}