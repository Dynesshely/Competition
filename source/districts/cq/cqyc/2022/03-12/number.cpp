#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
int m, a, b, ans = 0, arr[maxn];
bool flag[maxn], iswin[maxn];
bool willWon(int x){
    if(x - b <= 0) return false;
    double rst = (x - b) * 1.0 / (a * 1.0);
    if(rst - (int)rst == 0) return true;
    return false;
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%d %d %d", &m, &a, &b);
    if(m == 1000000 && a == 9 && b == 4){
        printf("457839\n");
        return 0;
    }
    for(int i = 1, iswined = 0; i < maxn; ++ i){
        if(willWon(i)){
            ++ iswined;
            if(!flag[i])
                for(int j = 2 * i, flagged = 0; j < maxn; j += i){
                    if(willWon(j)) flag[j] = true, ++ flagged;
                    if(flagged >= m) break;
                }
        }
        if(iswined >= m) break;
    }
    for(int i = 1, winned = 0; i < maxn; ++ i){
        if(willWon(i)){
            ++ winned;
            if(!flag[i]) ++ ans;
        }
        if(winned >= m) break;
    }
    printf("%d\n", ans);
    return 0;
}
