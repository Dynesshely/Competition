// Copyright (c) Catrol 2022.
// All Rights Reserved.

#include <bits/stdc++.h>

const int maxn = 1e4 + 5;
const int maxt = 1e3 + 5;

int t, n, cnt = 1, f[maxt], w[maxn], v[maxn], s[maxn];
int mw[maxn], mv[maxn];

inline void getDeltaTime(int *minutes) {
    int a, b, c, d;
    scanf("%d:%d %d:%d", &a, &b, &c, &d);
    *minutes = (c - a - 1) * 60 + d + (60 - b);
}

template <typename T> inline T max(T a, T b) { return a > b ? a : b; }

int main() {
    getDeltaTime(&t);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &w[i], &v[i], &s[i]);

        if (s[i] == 0)
            for (int j = w[i]; j <= t; ++j)
                f[j] = max(f[j], f[j - w[i]] + v[i]);
        else if (s[i] == 1)
            for (int j = t; j >= w[i]; --j)
                f[j] = max(f[j], f[j - w[i]] + v[i]);
        else
            for (int j = t; j >= w[i]; --j)
                for (int k = 1; k <= s[i] && k * w[i] <= j; ++k)
                    f[j] = max(f[j], f[j - k * w[i]] + k * v[i]);
    }
    printf("%d\n", f[t]);
}

// int main() {
//     getDeltaTime(&t);
//     scanf("%d", &n);
//     for (int i = 1; i <= n; ++ i) {
//         scanf("%d %d %d", &w[i], &v[i], &s[i]);
//
//         int a = w[i], b = v[i], c = s[i];
//         for (int j = 1; j <= c; j <<= 1)
//             mv[++ cnt] = j * a, mw[cnt] = j * b, c -= j;
//         if (c) mv[++ cnt] = a * c, mw[cnt] = b * c;
//     }
//     for (int i = 1; i <= cnt; ++ i) {
//         if (i <= n)
//             if (s[i] == 0)                                  //  完全背包
//                 for (int j = w[i]; j <= t; ++ j)
//                     f[j] = max(f[j], f[j - w[i]] + v[i]);
//             else if (s[i] == 1)                             //  01背包
//                 for (int j = t; j >= w[i]; -- j)
//                     f[j] = max(f[j], f[j - w[i]] + v[i]);
//         if (s[i] != 0 && s[i] != 1)                         //  多重背包
//             for (int j = t; j >= mw[i]; -- j)
//                 f[j] = max(f[j], f[j - mw[i]] + mv[i]);
//     }
//     printf("%d\n", f[t]);
//     return 0;
// }
