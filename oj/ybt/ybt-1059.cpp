#include <bits/stdc++.h>
using namespace std;
int n, sum = 0, tmp;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){ scanf("%d", &tmp); sum += tmp; }
    printf("%0.2f\n", sum * 1.0 / (n * 1.0));
    return 0;
}