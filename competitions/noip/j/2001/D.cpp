// NOIP 2001 装箱问题

// Copyright (c) Catrol 2022.
// All Rights Reserved.

#include <bits/stdc++.h>

const int maxv = 20000 + 3;
const int maxn = 30 + 3;

int V, n, dp[maxv], W[maxn], D[maxn];

int main(){
    scanf("%d\n%d", &V, &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &W[i]);
        D[i] = W[i];
        for(int j = V; j >= 1; --j)
            if(j >= W[i])
                dp[j] = std::max(dp[j], dp[j - W[i]] + D[i]);
    }
    printf("%d\n", V - dp[V]);
    return 0;
}
