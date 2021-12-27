#include <bits/stdc++.h>
using namespace std;
const int maxx = 10010000;
int T, x, last = 1, ne[maxx];
bool via[maxx];
bool c7(int x){
    int remain = 0;
    while(x){
        remain = x % 10;
        if (remain == 7) return true;
        x = x / 10;
    }
    return false;
}
int main(){
	for(int i = 2; i <= maxx; ++ i)
        if(via[i] == 0 && c7(i))
            for(int j = i; j <= maxx; j += i) via[j] = 1;
        else if(via[i] == 0) ne[last] = i, last = i;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++ i){
        int tmp; scanf("%d", &tmp);
        if(via[tmp]) printf("-1\n");
        else printf("%d\n", ne[tmp]);
    }
	return 0;
}
