#include <bits/stdc++.h>
using namespace std;

const int MOD  = 998244353;
const int MAXN = 100005;

int       n, a[MAXN];
long long sum[MAXN];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
}

void process() {
    map<int, int> last;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        int  x  = a[i];
        auto it = last.find(x);
        if (it == last.end()) {
            sum[i] = 2 * (sum[i - 1] + 1) % MOD;
        } else {
            int       p  = it->second;
            long long t1 = 2 * (sum[i - 1] + 1) % MOD;
            long long t2 = (sum[p - 1] + 1) % MOD;
            sum[i]       = (t1 - t2 + MOD) % MOD;
        }
        last[x] = i;
    }
}

void output() {
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + sum[i]) % MOD;
    printf("%lld\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
