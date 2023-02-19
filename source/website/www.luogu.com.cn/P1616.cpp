// Copyright (c) Catrol 2022.
// All Rights Reserved.

#include <bits/stdc++.h>

template <typename T>

inline T max(T a, T b){ return a > b ? a : b; }

const int maxn = 1e4 + 5;
const int maxm = 1e7 + 5;

int n, m, w[maxn], v[maxn];
long long f[maxm];

int main(){
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d %d", &w[i], &v[i]);
        for(int j = w[i]; j <= m; ++ j)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    }
    printf("%lld\n", f[m]);
    return 0;
}

