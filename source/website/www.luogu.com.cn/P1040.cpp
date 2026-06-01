#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[32][32];
int root[32][32], n, score[32];
void preorder(int l, int r) {
    if (l > r) return;
    int k = root[l][r];
    printf("%d ", k);
    preorder(l, k - 1);
    preorder(k + 1, r);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &score[i]);
    for (int i = 1; i <= n; ++i) dp[i][i] = score[i], root[i][i] = i;
    for (int len = 2; len <= n; ++len)
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            for (int k = l; k <= r; ++k) {
                ll L = (k > l) ? dp[l][k - 1] : 1;
                ll R = (k < r) ? dp[k + 1][r] : 1;
                ll val = L * R + score[k];
                if (val > dp[l][r]) { dp[l][r] = val; root[l][r] = k; }
            }
        }
    printf("%lld\n", dp[1][n]);
    preorder(1, n);
    putchar('\n');
    return 0;
}
