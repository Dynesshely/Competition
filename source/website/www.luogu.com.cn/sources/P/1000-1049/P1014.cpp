#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// P1014 [NOIP 1999 普及组] Cantor 表
// 之字形对角线遍历。找到 N 所在的对角线 k:
// 前 k-1 条对角线共 term = k(k-1)/2 项
// 在第 k 条对角线的第 pos = N - term 项
// k 奇数: (k-pos+1)/(pos)
// k 偶数: (pos)/(k-pos+1)

int main() {
    ll N;
    scanf("%lld", &N);

    // 对角线 k 包含项号: [(k-1)k/2+1, k(k+1)/2]
    // 二分：找最小 k 使 k(k+1)/2 >= N
    ll lo = 1, hi = 10000;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (mid * (mid + 1) / 2 >= N)
            hi = mid;
        else
            lo = mid + 1;
    }
    ll k = lo;
    ll prev = (k - 1) * k / 2;
    ll pos = N - prev;

    ll num, den;
    if (k & 1) {
        num = k - pos + 1;
        den = pos;
    } else {
        num = pos;
        den = k - pos + 1;
    }
    printf("%lld/%lld\n", num, den);
    return 0;
}
