#include <bits/stdc++.h>
using namespace std;
int m, n, tmp, ans = 0;
int main(){
    scanf("%d %d", &m, &n);
    while(m --){ scanf("%d", &tmp); if(tmp == n) ++ ans; }
    printf("%d\n", ans);
    return 0;
}