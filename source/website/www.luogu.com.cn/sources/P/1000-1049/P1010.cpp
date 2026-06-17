#include <bits/stdc++.h>
using namespace std;

// P1010 [NOIP 1998 普及组] 幂次方
// 递归分解：将 n 表示为 2^a + 2^b + ... 的形式，
// 指数也递归分解。2 直接用 "2"，2^0 用 "2(0)"。

string solve(int n) {
    if (n == 0) return "0";

    string res;
    for (int i = 15; i >= 0; --i) { // n ≤ 20000 < 2^15 = 32768
        if (n & (1 << i)) {
            if (!res.empty()) res += "+";
            if (i == 0)
                res += "2(0)";
            else if (i == 1)
                res += "2";
            else
                res += "2(" + solve(i) + ")";
        }
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    cout << solve(n) << '\n';
    return 0;
}
