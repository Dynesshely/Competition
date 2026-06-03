#include <bits/stdc++.h>
using namespace std;

int stairs[10005][105], num[10005][105], cntStairs[10005];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        cntStairs[i] = 0;
        for (int j = 0; j < m; ++j) {
            scanf("%d%d", &stairs[i][j], &num[i][j]);
            if (stairs[i][j]) ++cntStairs[i];
        }
    }
    int cur;
    scanf("%d", &cur);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + num[i][cur]) % 20123;
        int x = num[i][cur];
        if (cntStairs[i] == 0) continue;
        x = (x - 1) % cntStairs[i] + 1;
        int cnt = 0, j = cur;
        while (true) {
            if (stairs[i][j]) ++cnt;
            if (cnt == x) { cur = j; break; }
            j = (j + 1) % m;
        }
    }
    printf("%d\n", ans);
    return 0;
}
