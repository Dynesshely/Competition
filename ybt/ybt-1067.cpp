#include <bits/stdc++.h>
using namespace std;
int k, c1 = 0, c5 = 0, c10 = 0, tmp;
int main(){
    scanf("%d", &k);
    while(k --){
        scanf("%d", &tmp);
        switch(tmp){
            case 1: ++ c1; break;
            case 5: ++ c5; break;
            case 10: ++ c10; break;
        }
    }
    printf("%d\n%d\n%d\n", c1, c5, c10);
    return 0;
}