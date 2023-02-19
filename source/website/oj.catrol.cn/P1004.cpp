#include <bits/stdc++.h>
using namespace std;

int main(){
    int i, d;
    scanf("%d %d", &i, &d);
    if(i == 0){
        printf("Nice!\n");
        return 0;
    }
    printf("%.3f\n", (double)d / i);
    return 0;
}