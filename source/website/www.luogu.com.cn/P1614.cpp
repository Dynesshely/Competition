#include <bits/stdc++.h>
using namespace std;

int a[3005];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int cur = 0;
    for (int i = 0; i < m; i++) {
        cur += a[i];
    }
    int ans = cur;
    for (int i = m; i < n; i++) {
        cur += a[i] - a[i - m];
        if (cur < ans) ans = cur;
    }
    printf("%d\n", ans);
    return 0;
}
