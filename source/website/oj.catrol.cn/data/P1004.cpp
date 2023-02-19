#include <bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    int n = 10;
    for(int i = 1; i <= n; ++ i){
    	ostringstream ss1, ss2;
        ss1 << "P1004/pf" << i << ".in";
        ss2 << "P1004/pf" << i << ".ans";
        int tot = rand() % 1000, ded = rand() % tot - 1;
        if(tot < 0) tot = 0;
        freopen(ss1.str().c_str(), "w", stdout);
        printf("%d %d\n", tot, ded);
        freopen(ss2.str().c_str(), "w", stdout);
        if(tot == 0){
            printf("Nice!\n");
            continue;
        }
        printf("%.3f\n", (double)ded / tot);
    }
    return 0;
}