#include <bits/stdc++.h>
using namespace std;
int _map[200][200], maxn, maxi, d, n, i, j, x, y, k, m, ans;
int main() {
    scanf("%d", &d);
    memset(_map, 0, sizeof(_map));
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d %d %d", &x, &y, &k);
        _map[x][y] = k;
    }
    maxn = 0, maxi = 0;
    for (i = 0, j = 0; i <= 128 && j <= 128; i = j == 128 ? i + 1 : i, j = j == 128 ? 0 : j + 1) {
        ans = 0;
        for (k = max(0, i - d); k <= min(128, i + d); ++k)
            for (m = max(0, j - d); m <= min(128, j + d); ++m)
                ans += _map[k][m];
        if (ans == maxn)
            maxi++;
        if (ans > maxn) {
            maxn = ans;
            maxi = 1;
        }
    }
    printf("%d %d\n", maxi, maxn);
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int d, n, ans = 1, tot, _map[170][170], x, y, k, bor = 128 + 20;
// int main() {
//     scanf("%d %d", &d, &n);
//     for (int i = 1; i <= n; i++) {
//         scanf("%d %d %d", &x, &y, &k);
//         _map[x + 20][y + 20] = k;
//     }
//     for (int i = 20, j = 20; i <= bor && j <= bor; i = j == bor ? i + 1 : i, j = j == bor ? 20 : j + 1) {
//         int sum = 0, rr = j + d, ll = j - d, uu = i - d, dd = i + d;
//         for (int k = uu, l = ll; k <= dd && l <= rr; k = l == dd ? k + 1 : k, l = l == dd ? ll : l + 1)
//             sum += _map[k][l];
//         if (tot == sum)
//             ans++;
//         if (tot < sum)
//             ans = 1;
//         tot = max(tot, sum);
//     }
//     printf("%d %d\n", ans, tot);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int d, n, num[129][129], x, y, k;
// long long zone[129][129], fas = 0, biggest = 0;
// int main() {
//     scanf("%d %d", &d, &n);
//     for (int i = 0; i < n; ++i) {
//         scanf("%d %d %d", &x, &y, &k);
//         num[y][x] = k;
//     }
//     for (int i = d; i < 129 - d; ++i)
//         for (int j = d; j < 129 - d; ++j) {
//             for (int xx = i - d; xx <= i + d; ++xx)
//                 for (int yy = j - d; yy <= j + d; ++yy)
//                     zone[i][j] += num[yy][xx];
//             if (biggest < zone[i][j]) {
//                 biggest = zone[i][j];
//                 fas = 1;
//             } else if (biggest == zone[i][j]) {
//                 fas++;
//             }
//         }
//     printf("%lld %lld\n", fas, biggest);
//     return 0;
// }
