#include <bits/stdc++.h>
using namespace std;
const long long maxn = 4294967295;
int             f[maxn], t, last = 0, tmp;
bool            has7(long long x) {
    while (x) {
        if (x % 10 == 7)
            return true;
        x /= 10;
    }
    return false;
}
int main() {
    printf("%lld\n", maxn);
    for (long long i = 1; i < maxn; ++i) {
        if (has7(i)) {
            ++last;
            continue;
        }
        f[i] = last;
    }
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d", &tmp);
        printf("%d\n", tmp - f[tmp]);
    }
    return 0;
}