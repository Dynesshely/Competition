#include <bits/stdc++.h>
using namespace std;

// P1008 [NOIP 1998 普及组] 三连击
// 1..9 分成三组三位数，形成 1:2:3 比例

int main() {
    array<int, 9> d;
    for (int i = 0; i < 9; ++i) d[i] = i + 1;

    do {
        int a = d[0] * 100 + d[1] * 10 + d[2];
        int b = d[3] * 100 + d[4] * 10 + d[5];
        int c = d[6] * 100 + d[7] * 10 + d[8];
        if (b == 2 * a && c == 3 * a)
            printf("%d %d %d\n", a, b, c);
    } while (next_permutation(d.begin(), d.end()));

    return 0;
}
