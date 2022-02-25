#include <bits/stdc++.h>
using namespace std;
int n, gm = 0, sm = 0, rm = 0, t1, t2, t3;
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d", &t1, &t2, &t3);
        gm += t1, sm += t2, rm += t3;
    }
    printf("%d %d %d %d\n", gm, sm, rm, gm + sm + rm);
    return 0;
}