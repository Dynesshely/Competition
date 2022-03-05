#include <bits/stdc++.h>
using namespace std;
float sum = 0.0, tmp;
int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){ scanf("%f", &tmp); sum += tmp; }
    printf("%0.4f\n", sum / n);
    return 0;
}