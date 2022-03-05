#include <bits/stdc++.h>
using namespace std;
int T, M, t[101], w[101], dp[1001];
int main(){
    scanf("%d %d", &T, &M);
    for(int i = 1; i <= M; ++ i)
        scanf("%d %d", &t[i], &w[i]);
    for(int i = 1; i <= M; ++ i){
        for(int j = T; j >= t[i]; -- j){
            dp[j] = max(dp[j], dp[j - t[i]] + w[i]);
        }
    }
    printf("%d\n", dp[T]);
    return 0;
}