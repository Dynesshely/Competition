#include <bits/stdc++.h>
using namespace std;

const int maxn = 500050;
int n, m, q, a[5010], tre[maxn], held[maxn];
int main(){
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);

    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; ++ i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= q; ++ i){
        int opt, l, r, x;
        scanf("%d %d %d %d", &opt, &l, &r, &x);
        if(opt == 1){
            for(int j = l; j <= r; ++ j){
                // 无人占领且有宝藏
                if(a[j] == 0 && tre[j] != 0)
                    held[x] += tre[j];
                tre[j] = 0; a[j] = x;
            }
        }else
            for(int j = l; j <= r; ++ j){
                tre[j] += x;
                if(a[j] != 0){
                    held[a[j]] += tre[j];
                    tre[j] = 0;
                }
            }
    }
    for(int i = 1; i <= m; ++ i)
        printf("%d\n", held[i]);
    return 0;
}