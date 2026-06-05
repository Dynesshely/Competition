#include <bits/stdc++.h>
using namespace std;

int n, ans, cnt2;

void input() { scanf("%d", &n); }

void process() {
    ans  = 1;
    cnt2 = 0;
    for (int i = 2; i <= n; ++i) {
        int x = i;
        if (!(x & 1)) {
            int tz = __builtin_ctz(x);
            x >>= tz;
            cnt2 += tz;
        }
        while (x % 5 == 0) {
            x /= 5;
            --cnt2;
        }
        ans = ans * (x % 10) % 10;
    }
    if (cnt2 > 0) {
        const int tbl[] = {2, 4, 8, 6};
        cnt2            = (cnt2 - 1) & 3;
        ans             = ans * tbl[cnt2] % 10;
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
