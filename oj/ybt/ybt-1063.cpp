#include <bits/stdc++.h>
using namespace std;
int n, low = 0x3f, high = -0x3f, tmp;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &tmp);
        low = min(low, tmp);
        high = max(high, tmp);
    }
    printf("%d\n", high - low);
    return 0;
}