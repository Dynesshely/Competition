#include <bits/stdc++.h>
using namespace std;

int m, n, cnt[10];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; i++) {
        int x = i;
        while (x) {
            cnt[x % 10]++;
            x /= 10;
        }
    }
    for (int i = 0; i < 9; i++) printf("%d ", cnt[i]);
    printf("%d", cnt[9]);
    return 0;
}
