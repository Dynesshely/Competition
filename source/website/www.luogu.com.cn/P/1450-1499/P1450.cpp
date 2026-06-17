#include <bits/stdc++.h>
using namespace std;

int       c[5], d[5], n, s;
long long f[100005];

void input() { scanf("%d%d%d%d%d", &c[1], &c[2], &c[3], &c[4], &n); }

void process() {
    f[0] = 1;
    for (int i = 1; i <= 4; i++)
        for (int j = c[i]; j <= 100000; j++)
            f[j] += f[j - c[i]];
}

void output() {
    while (n--) {
        scanf("%d%d%d%d%d", &d[1], &d[2], &d[3], &d[4], &s);
        long long ans = 0;
        for (int mask = 0; mask < 16; mask++) {
            int       bits = __builtin_popcount(mask);
            long long sum  = s;
            for (int i = 0; i < 4; i++)
                if (mask >> i & 1)
                    sum -= 1LL * (d[i + 1] + 1) * c[i + 1];
            if (sum >= 0) {
                if (bits & 1)
                    ans -= f[sum];
                else
                    ans += f[sum];
            }
        }
        printf("%lld\n", ans);
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
