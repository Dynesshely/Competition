#include <bits/stdc++.h>
using namespace std;
int n;
float x;
int main(){
    scanf("%f %d", &x, &n);
    for(int i = 1; i <= n; ++ i) x += x * 0.001;
    printf("%0.4f\n", x);
    return 0;
}