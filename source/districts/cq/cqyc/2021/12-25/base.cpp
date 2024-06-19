#include <bits/stdc++.h>
using namespace std;
int ans[2000], en = 0, n;
int main() {
    freopen("base.in", "r", stdin);
    freopen("base.out", "w", stdout);
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    while (n) {
        ans[en] = n & 1;
        n >>= 1;
        if ((en & 1) && (ans[en] & 1))
            ++n;
        ++en;
    }
    if (en)
        for (int i = en - 1; i >= 0; --i)
            printf("%d", ans[i]);
    printf("\n");
    return 0;
}