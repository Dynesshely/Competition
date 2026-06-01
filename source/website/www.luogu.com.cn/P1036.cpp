#include <bits/stdc++.h>
using namespace std;
int n, k, x[22], ans;
bool is_prime(int s) {
    if (s < 2) return false;
    for (int d = 2; d * d <= s; ++d)
        if (s % d == 0) return false;
    return true;
}
void dfs(int idx, int cnt, int sum) {
    if (cnt == k) { ans += is_prime(sum); return; }
    if (idx > n) return;
    dfs(idx + 1, cnt + 1, sum + x[idx]);
    dfs(idx + 1, cnt, sum);
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
    dfs(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}
