#include <bits/stdc++.h>
using namespace std;

const int N = 200100, H = 22;

int s[N], t[N], a[N], b[N];
int nxt[H + 1][N], lazy[H + 1][N];
int n, cur, head = 1;

void pushDown(int r, int x) {
    if (r == 0)
        return;
    bool first = true;
    for (int u = x; u != nxt[r][x]; u = nxt[r - 1][u]) {
        if (!first)
            a[u] -= lazy[r][x];
        first = false;
        lazy[r - 1][u] += lazy[r][x];
    }
    lazy[r][x] = 0;
}

int getH() {
    for (int i = 0; i < H; ++i)
        if (rand() % 2)
            return i;
    return H;
}

bool cmp(int x, int y) { return b[x] - a[x] >= b[y] - a[y]; }

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &s[i], &t[i]);
    ++cur;
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        ++cur;
        a[cur] = s[i];
        int h  = getH();
        int x  = head;
        for (int r = H; r >= 0; --r) {
            while (nxt[r][x] && a[nxt[r][x]] < a[cur])
                x = nxt[r][x];
            pushDown(r, x);
        }
        int val = b[x] - a[x] + s[i] + t[i];
        b[cur]  = val;
        if (val > ans)
            ans = val;
        x = head;
        --a[x];
        for (int r = H; r >= 0; --r) {
            while (nxt[r][x] && a[nxt[r][x]] < a[cur]) {
                ++lazy[r][x];
                x = nxt[r][x];
                --a[x];
            }
            pushDown(r, x);
            while (nxt[r][x] && cmp(cur, nxt[r][x])) {
                pushDown(r, nxt[r][x]);
                nxt[r][x] = nxt[r][nxt[r][x]];
            }
            if (h >= r) {
                nxt[r][cur] = nxt[r][x];
                nxt[r][x]   = cur;
            }
        }
        --a[cur];
    }
    printf("%d\n", ans);
    return 0;
}
