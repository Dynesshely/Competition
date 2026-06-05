#include <bits/stdc++.h>
using namespace std;

const int N = 20010, M = 860000, MAXN = 2100000, U = 300010, P = 1234567;

int                     n, m, gr[N], nxt[N], sub[M], rgt[M], ans;
char                    buf[9];
map<int, int>           mp[N];
map<int, int>::iterator it;

int  tmp[U], tag[MAXN];
bool has[MAXN];

struct E {
    int x, y;
    E() {}
    E(int x_, int y_) { x = x_, y = y_; }
} que[U], edg[U * 2];

inline bool cmp(const E &a, const E &b) { return a.x < b.x; }

inline void doAdd(int &a, int b) { a = a + b < P ? a + b : a + b - P; }

inline void doMul(int x, int p) { tag[x] = 1LL * tag[x] * p % P; }

inline void doPush(int x) {
    if (tag[x] != 1)
        doMul(x << 1, tag[x]), doMul(x << 1 | 1, tag[x]), tag[x] = 1;
}

void build(int x, int a, int b) {
    if (a == b)
        return;
    tag[x]  = 1;
    int mid = (a + b) >> 1;
    build(x << 1, a, mid), build(x << 1 | 1, mid + 1, b);
}

void doIns(int x, int a, int b, int c, int p) {
    if (a == b) {
        doAdd(tag[x], p);
        has[x] = !!tag[x];
        return;
    }
    doPush(x);
    int mid = (a + b) >> 1;
    if (c <= mid)
        doIns(x << 1, a, mid, c, p);
    else
        doIns(x << 1 | 1, mid + 1, b, c, p);
    has[x] = has[x << 1] | has[x << 1 | 1];
}

void doMulRange(int x, int a, int b, int c, int d, int p) {
    if (c <= a && b <= d) {
        doMul(x, p);
        return;
    }
    doPush(x);
    int mid = (a + b) >> 1;
    if (c <= mid)
        doMulRange(x << 1, a, mid, c, d, p);
    if (d > mid)
        doMulRange(x << 1 | 1, mid + 1, b, c, d, p);
}

int doAsk(int x, int a, int b, int c) {
    if (a == b)
        return tag[x];
    doPush(x);
    int mid = (a + b) >> 1;
    return c <= mid ? doAsk(x << 1, a, mid, c) : doAsk(x << 1 | 1, mid + 1, b, c);
}

void doCollect(int x, int a, int b, map<int, int> &f) {
    if (!has[x])
        return;
    if (a == b) {
        if (tag[x])
            doAdd(f[a << 4 & 1048575], tag[x]);
        tag[x] = has[x] = 0;
        return;
    }
    doPush(x);
    int mid = (a + b) >> 1;
    doCollect(x << 1, a, mid, f), doCollect(x << 1 | 1, mid + 1, b, f);
    has[x] = 0;
}

inline void doSolve() {
    int i, j, cnt = 0, s = 0;
    for (i = 0; i < m; ++i) {
        tmp[i] = 0;
        for (j = sub[que[i].x]; ~j; j = sub[j])
            doAdd(tmp[i], doAsk(1, 0, M, j));
        edg[++cnt] = E(que[i].x, que[i].y);
        edg[++cnt] = E(rgt[que[i].x], P - que[i].y);
    }
    sort(edg + 1, edg + cnt + 1, cmp);
    for (i = 1; i <= cnt; ++i) {
        if (i > 1 && edg[i].x > edg[i - 1].x)
            doMulRange(1, 0, M, edg[i - 1].x, edg[i].x - 1, s);
        doAdd(s, edg[i].y);
    }
    for (i = 0; i < m; ++i)
        if (tmp[i])
            doIns(1, 0, M, que[i].x, 1LL * que[i].y * tmp[i] % P);
}

int main() {
    int i, j, x, y;
    scanf("%d%d", &n, &m);
    for (i = 2; i <= n; ++i)
        scanf("%d", &x), nxt[i] = gr[++x], gr[x] = i;
    for (int t = m; t--;) {
        scanf("%d%s", &x, buf);
        for (y = j = 0; j < 5; ++j)
            y = y << 4 | (buf[j] - '0' + 1);
        mp[x + 1][y] = P - 1;
    }
    sub[0] = -1, rgt[0] = M;
    for (int i = 1; i < M; ++i)
        for (int j = 0;; ++j)
            if (i >> (j * 4) & 15) {
                sub[i] = i - (((i >> (j * 4)) & 15) << (j * 4));
                rgt[i] = i + (1 << (j * 4));
                break;
            }
    build(1, 0, M);
    for (int i = n; i; --i) {
        for (int j = 1; j <= 10; ++j)
            mp[i][j << 16] = 1;
        for (it = mp[i].begin(); it != mp[i].end(); ++it)
            doIns(1, 0, M, it->first, it->second);
        for (int j = gr[i]; j; j = nxt[j]) {
            m = 0;
            for (it = mp[j].begin(); it != mp[j].end(); ++it)
                que[m++] = E(it->first, it->second);
            doSolve();
        }
        mp[i].clear();
        doCollect(1, 0, M, mp[i]);
    }
    for (ans = i = 1; i <= n; ++i)
        ans = ans * 10 % P;
    doAdd(ans, P - mp[1][0]);
    return printf("%d", ans), 0;
}
