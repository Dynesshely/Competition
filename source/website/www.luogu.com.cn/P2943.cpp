#include <bits/stdc++.h>
int min(int a, int b) { return a < b ? a : b; }
int n, m, pos[205], f[40005], p[40005], last[40005], pre[40005], nex[40005], cnt[205];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        pre[i]          = last[p[i]];
        nex[last[p[i]]] = i;
        last[p[i]]      = i;
        f[i]            = 1e9;
        nex[i]          = n + 1;
    }
    int t = sqrt(n);
    for (int i = 1; i <= t; i++)
        pos[i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= t; j++) {
            if (pre[i] < pos[j])
                cnt[j]++;
            if (cnt[j] > j) {
                cnt[j]--;
                while (nex[pos[j]] < i)
                    pos[j]++;
                pos[j]++;
            }
            f[i] = min(f[pos[j] - 1] + j * j, f[i]);
        }
    printf("%d\n", f[n]);
}