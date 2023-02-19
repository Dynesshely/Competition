
// Copyright (c) Catrol 2022.
// All Rights Reserved.

#include <bits/stdc++.h>

const int maxm = 12880 + 3;
const int maxn = 3402 + 3;
int N, M, W[maxn], D[maxn], dp[maxm];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++ i) {
        scanf("%d %d", &W[i], &D[i]);
        for(int j = M; j >= W[i]; -- j)
            dp[j] = std::max(dp[j], dp[j - W[i]] + D[i]);
    }
    printf("%d\n", dp[M]);
    return 0;
}
