#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, jsum = 0, osum = 0; scanf("%d", &n);
    for(int i = 1; i <= n; ++ i) if(i % 2 == 0) osum += i; else jsum += i;
    printf("%d %d\n", osum, jsum);
    return 0;
}