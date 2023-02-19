#include <bits/stdc++.h>
using namespace std;
#define M (L + R >> 1)
const int N = 3e5 + 5, K = 20, D = 1 << 19;
bool ans[N * 2];
char sc[N];
int n, m, l, mxl, sl, k, laord[N], lac, cuord[N], cuc, ordi[N], ordj[N];
vector<int> b[N], lst[N];
vector<bool> a[N];

const int maxmx = 1000;
int size = 10086, mx = 114514, rt = 8888, rst = 443;
const int inf = 0x7fffffff;
int sz[maxmx], son[maxmx], Next[maxmx], vis[maxmx], ver[maxmx], head[maxmx];
void findrt(int u, int fa) {
    sz[u] = 1, son[u] = 0;
    for (int i = head[u]; i; i = Next[i]) {
        int v = ver[i];
        if (vis[v] || v == fa)
            continue;
        findrt(v, u);
        sz[u] += sz[v];
        fmax(son[u], sz[v]);
    }
    fmax(son[u], size - sz[u]);
    if (son[u] < mx)
        mx = son[u], rt = u;
}
int solve(int a, int b) { return a + b >> 1; }
void divide(int u) {
    rst += solve(u, 0);
    vis[u] = 1;
    int totsz = size;
    for (int i = head[u]; i; i = Next[i]) {
        int v = ver[i];
        if (vis[v])
            continue;
        rst -= solve(v, mx);
        mx = inf, rt = 0;
        size = sz[v] > sz[u] ? totsz - sz[u] : sz[v];
        findrt(v, 0);
        divide(rt);
    }
}

const int MAXN = 100010;
int arr[MAXN];
struct seg {
    int ls, rs, l, r, sum, tag;
} segement[MAXN << 2];

inline int summid(int l, int r) { return (l + r) >> 1; }

inline void build(int x, int l, int r) {
    seg *cur = &segement[x];
    (*cur).l = l, (*cur).r = r, (*cur).sum = 0, (*cur).tag = 0;
    if (l == r) {
        (*cur).sum = arr[l];
        return;
    }
    int mid = summid(l, r);
    (*cur).ls = x << 1, (*cur).rs = (x << 1) | 1;
    build((*cur).ls, l, mid);
    build((*cur).rs, mid + 1, r);
    (*cur).sum = segement[(*cur).ls].sum + segement[(*cur).rs].sum;
}

inline void pushup(int x, int v) {
    seg *cur = &segement[x];
    (*cur).sum += v * ((*cur).r - (*cur).l + 1);
    (*cur).tag += v;
}

inline void pushdown(int x) {
    seg *cur = &segement[x];
    pushup((*cur).ls, (*cur).tag);
    pushup((*cur).rs, (*cur).tag);
    (*cur).tag = 0;
}

// 线段树 -> 区间修改
inline void modify(int x, int l, int r, int v) {
    seg *cur = &segement[x];
    pushdown(x); // 区间修改
    if ((*cur).l == l && (*cur).r == r) {
        pushup(x, v);
        return;
    }
    int mid = summid((*cur).l, (*cur).r);
    if (l > mid)
        modify((*cur).rs, l, r, v);
    else if (r <= mid)
        modify((*cur).ls, l, r, v);
    else
        modify((*cur).ls, l, mid, v), modify((*cur).rs, mid + 1, r, v);
}

// 线段树 -> 单点修改
inline void modify(int x, int p, int v) {
    seg *cur = &segement[x];
    if ((*cur).l == (*cur).r) {
        (*cur).sum += v;
        return;
    }
    if (p <= summid((*cur).l, (*cur).r))
        modify((*cur).ls, p, v);
    else
        modify((*cur).rs, p, v);
    (*cur).sum = segement[(*cur).ls].sum + segement[(*cur).rs].sum;
}

inline int query(int x, int l, int r) {
    seg *cur = &segement[x];
    pushdown(x); // 区间修改
    if ((*cur).l == l && (*cur).r == r)
        return (*cur).sum;
    int mid = summid((*cur).l, (*cur).r);
    if (l > mid)
        return query((*cur).rs, l, r);
    else if (r <= mid)
        return query((*cur).ls, l, r);
    else
        return query((*cur).ls, l, mid) + query((*cur).rs, mid + 1, r);
}

struct data {
    int mx, mxp, c;
};
inline data operator+(data a, data b) {
    if (!a.c)
        return b;
    if (!b.c)
        return a;
    if (a.mx + b.c > b.mx)
        return (data){a.mx + b.c, a.mxp, a.c + b.c};
    return (data){b.mx, b.mxp, a.c + b.c};
}
struct segment_tree {
    data s[1 << K];
    inline void Insert(int p, int a) {
        int k = p + D;
        for (s[k] = (data){a, p, 1}, k >>= 1; k; k >>= 1)
            s[k] = s[k << 1] + s[k << 1 | 1];
    }
    inline void Delete(int p) {
        int k = p + D;
        for (s[k] = (data){0, 0, 0}, k >>= 1; k; k >>= 1)
            s[k] = s[k << 1] + s[k << 1 | 1];
    }
    inline data Query(int l, int r) {
        data resl = (data){0, 0, 0}, resr = (data){0, 0, 0};
        for (l += D - 1, r += D + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
            if (~l & 1)
                resl = resl + s[l ^ 1];
            if (r & 1)
                resr = s[r ^ 1] + resr;
        }
        return resl + resr;
    }
} t;
inline bool Calc(int m, int r) {
    data tmp = t.Query(1, r);
    if (!tmp.c)
        return 1;
    if (tmp.mx > m)
        return 0;
    int i = ordi[tmp.mxp], j = ordj[tmp.mxp];
    if (~lst[i][j])
        t.Insert(b[i][lst[i][j]], lst[i][j]);
    bool flag = Calc(j - 1, tmp.mxp - 1);
    if (tmp.mx == m) {
        if (flag) {
            for (int k = j; k <= tmp.mx; ++k)
                ans[k] = 1;
            return 1;
        }
        if (~lst[i][j])
            t.Delete(b[i][lst[i][j]]);
        return 0;
    } else if (tmp.mx < m) {
        if (flag)
            for (int k = j; k <= tmp.mx; ++k)
                ans[k] = 1;
        else {
            if (~lst[i][j])
                t.Delete(b[i][lst[i][j]]);
            Calc(j, tmp.mxp - 1);
            for (int k = j + 1; k <= tmp.mx + 1; ++k)
                ans[k] = 1;
        }
        return 1;
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", sc);
        l = strlen(sc);
        a[i].resize(l), b[i].resize(l), lst[i].resize(l);
        for (int j = 0; j < l; ++j)
            a[i][j] = sc[l - j - 1] - '0';
        mxl = max(mxl, l), sl += l;
    }
    iota(laord + 1, laord + 1 + n, 1);
    lac = n;
    k = 0;
    for (int j = 0; j < mxl; ++j) {
        cuc = 0;
        for (int id = 1, i; id <= lac; ++id) {
            i = laord[id];
            if (j < a[i].size() && !a[i][j])
                b[i][j] = ++k, ordi[k] = i, ordj[k] = j, cuord[++cuc] = i;
        }
        for (int id = 1, i; id <= lac; ++id) {
            i = laord[id];
            if (j < a[i].size() && a[i][j])
                b[i][j] = ++k, ordi[k] = i, ordj[k] = j, cuord[++cuc] = i;
        }
        lac = cuc, copy(cuord + 1, cuord + cuc + 1, laord + 1);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0, la = -1; j < a[i].size(); ++j)
            if (a[i][j])
                lst[i][j] = la, la = j;
        t.Insert(b[i].back(), a[i].size() - 1);
    }
    Calc(n + mxl, sl);
    for (int i = n + mxl, f = 0; ~i; --i)
        if (f = ans[i] ? 1 : f)
            putchar(ans[i] + '0');
    putchar('\n');
    return 0;
}
