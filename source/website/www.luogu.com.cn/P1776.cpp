// Copyright (c) Catrol 2022.
// All Rights Reserved.

#include <bits/stdc++.h>

template <typename T> inline T max(T a, T b) { return a > b ? a : b; }

//  ||=======================||
//  ||  Solution 1 (60 pts)  ||
//  ||=======================||

// const int maxn = 100 + 5;
// const int maxw = 1e4 * 4 + 5;
//
// int n, W, v[maxn], w[maxn], m[maxn];
// long long dp[maxw];
//
// int main() {
//     scanf("%d %d", &n, &W);
//     for (int i = 1; i <= n; ++ i) {
//         scanf("%d %d %d", &v[i], &w[i], &m[i]);
//         for (int j = W; j >= w[i]; -- j)
//             for (int k = 1; k <= m[i] && k * w[i] <= j; ++ k)
//                 dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
//     }
//     printf("%lld\n", dp[W]);
//     return 0;
// }

//  ||========================||
//  ||  Solution 2 (100 pts)  ||
//  ||========================||

const int maxx = 1e6 + 5;

int n, m, cnt = 1, f[maxx], w[maxx], v[maxx];

int main() {
    scanf("%d %d", &n, &m);

    int a, b, c;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        for (int j = 1; j <= c; j <<= 1)
            v[++cnt] = j * a, w[cnt] = j * b, c -= j;
        if (c)
            v[++cnt] = a * c, w[cnt] = b * c;
    }

    for (int i = 1; i <= cnt; ++i)
        for (int j = m; j >= w[i]; --j)
            f[j] = max(f[j], f[j - w[i]] + v[i]);

    printf("%d\n", f[m]);
    return 0;
}
