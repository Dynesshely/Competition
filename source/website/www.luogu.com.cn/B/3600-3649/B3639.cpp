#include <bits/stdc++.h>
using namespace std;

int n, m, a[1005];

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int x;
        scanf("%d", &x);
        a[x] ^= 1;
        int l = x == 1 ? n : x - 1;
        int r = x == n ? 1 : x + 1;
        a[l] ^= 1;
        a[r] ^= 1;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
