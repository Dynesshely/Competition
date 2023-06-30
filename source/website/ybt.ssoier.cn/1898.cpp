#include <bits/stdc++.h>
using namespace std;
struct point{
    double x;
    double y;
};
int main(){
    int turns; // 关卡总数
    scanf("%d", &turns);
    while(turns --){
        int n, m, ans = 0;
        scanf("%d %d", &n, &m);
        point pigs[n];
        for(int i = 0; i < n; i ++){
            scanf("%lf %lf", &pigs[i].x, &pigs[i].y);
        }
        switch(m){
            case 0:
                
                break;
            case 1: // 最多用 [n/3+1] 只小鸟即可消灭所有小猪
                break;
            case 2: // 一定存在一种最优解， 保证一只小鸟消灭了 [n/3] 只小猪
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}