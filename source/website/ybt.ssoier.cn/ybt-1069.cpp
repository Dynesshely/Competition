#include <bits/stdc++.h>
using namespace std;
int m, n, m1;
int main(){
    scanf("%d %d", &m, &n); m1 = m;
    for(int i = 2; i <= n; ++ i) m *= m1;
    printf("%d\n", m);
    return 0;
}