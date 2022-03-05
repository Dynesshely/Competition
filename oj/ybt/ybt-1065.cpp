#include <bits/stdc++.h>
using namespace std;
int m, n, sum = 0;
int main(){
    scanf("%d %d", &m, &n);
    for(int i = m; i <= n; ++ i)
        if(i % 2 != 0) sum += i;
    printf("%d\n", sum);
    return 0;
}