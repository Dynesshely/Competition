#include <bits/stdc++.h>
using namespace std;

int n, full;
int ty[16], tx[16], by[16], bx[16], c[16];
int dep[16], dp[1 << 16];
int colRects[21][16], colCnt[21];

int advance(int mask, int color) {
    int cur = mask;
    while (1) {
        int nxt = cur;
        for (int j = 0; j < colCnt[color]; ++j) {
            int i = colRects[color][j];
            if (!(nxt >> i & 1) && (dep[i] & ~nxt) == 0)
                nxt |= 1 << i;
        }
        if (nxt == cur)
            break;
        cur = nxt;
    }
    return cur;
}

int dfs(int mask) {
    if (mask == full)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];
    int ans = 100;
    for (int col = 1; col <= 20; ++col) {
        if (!colCnt[col])
            continue;
        int nxt = advance(mask, col);
        if (nxt != mask) {
            int val = 1 + dfs(nxt);
            if (val < ans)
                ans = val;
        }
    }
    return dp[mask] = ans;
}

void input() {
    scanf("%d", &n);
    full = (1 << n) - 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d%d", &ty[i], &tx[i], &by[i], &bx[i], &c[i]);
        colRects[c[i]][colCnt[c[i]]++] = i;
    }
}

void process() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && by[j] == ty[i] && tx[j] < bx[i] && tx[i] < bx[j])
                dep[i] |= 1 << j;
    memset(dp, -1, sizeof(dp));
}

void output() { printf("%d\n", dfs(0)); }

int main() {
    input();
    process();
    output();
    return 0;
}
