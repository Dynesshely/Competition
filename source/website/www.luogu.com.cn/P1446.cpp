#include <bits/stdc++.h>
using namespace std;

int sr, sb, sg, m, p, n;
int perm[65][65];
int dp[25][25];
int via[65];
int cyc[65];

void input() {
    scanf("%d%d%d%d%d", &sr, &sb, &sg, &m, &p);
    n = sr + sb + sg;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &perm[i][j]);
    for (int i = 1; i <= n; i++)
        perm[m + 1][i] = i;
}

int modPow(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1)
            r = r * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return r;
}

int calc(int *cur) {
    memset(via, 0, sizeof(via));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (via[i])
            continue;
        int len = 0, x = i;
        while (!via[x]) {
            via[x] = 1;
            x      = cur[x];
            len++;
        }
        cyc[cnt++] = len;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int tot  = 0;
    for (int i = 0; i < cnt; i++) {
        int L = cyc[i];
        int old[25][25];
        memcpy(old, dp, sizeof(dp));
        memset(dp, 0, sizeof(dp));
        for (int r = 0; r <= sr; r++) {
            for (int b = 0; b <= sb; b++) {
                int g = tot - r - b;
                if (g < 0 || g > sg)
                    continue;
                int val = old[r][b];
                if (!val)
                    continue;
                if (r + L <= sr)
                    dp[r + L][b] = (dp[r + L][b] + val) % p;
                if (b + L <= sb)
                    dp[r][b + L] = (dp[r][b + L] + val) % p;
                if (g + L <= sg)
                    dp[r][b] = (dp[r][b] + val) % p;
            }
        }
        tot += L;
    }
    return dp[sr][sb];
}

void process() {
    int ans = 0;
    for (int i = 1; i <= m + 1; i++)
        ans = (ans + calc(perm[i])) % p;
    ans = ans * modPow(m + 1, p - 2) % p;
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
