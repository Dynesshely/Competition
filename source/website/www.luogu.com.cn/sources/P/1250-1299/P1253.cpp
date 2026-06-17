#include <bits/stdc++.h>
using namespace std;

const long long NO_ASSIGN = LLONG_MAX;

int               n, q;
vector<long long> a, val, tagAdd, tagAssign;

void build(int u, int l, int r) {
    if (l == r) {
        val[u] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    val[u] = max(val[u * 2], val[u * 2 + 1]);
}

void applyAssign(int u, long long x) {
    val[u]       = x;
    tagAssign[u] = x;
    tagAdd[u]    = 0;
}

void applyAdd(int u, long long x) {
    val[u] += x;
    if (tagAssign[u] != NO_ASSIGN)
        tagAssign[u] += x;
    else
        tagAdd[u] += x;
}

void push(int u) {
    if (tagAssign[u] != NO_ASSIGN) {
        applyAssign(u * 2, tagAssign[u]);
        applyAssign(u * 2 + 1, tagAssign[u]);
        tagAssign[u] = NO_ASSIGN;
    }
    if (tagAdd[u] != 0) {
        applyAdd(u * 2, tagAdd[u]);
        applyAdd(u * 2 + 1, tagAdd[u]);
        tagAdd[u] = 0;
    }
}

void updateAssign(int u, int l, int r, int ql, int qr, long long x) {
    if (ql <= l && r <= qr) {
        applyAssign(u, x);
        return;
    }
    push(u);
    int mid = (l + r) / 2;
    if (ql <= mid)
        updateAssign(u * 2, l, mid, ql, qr, x);
    if (qr > mid)
        updateAssign(u * 2 + 1, mid + 1, r, ql, qr, x);
    val[u] = max(val[u * 2], val[u * 2 + 1]);
}

void updateAdd(int u, int l, int r, int ql, int qr, long long x) {
    if (ql <= l && r <= qr) {
        applyAdd(u, x);
        return;
    }
    push(u);
    int mid = (l + r) / 2;
    if (ql <= mid)
        updateAdd(u * 2, l, mid, ql, qr, x);
    if (qr > mid)
        updateAdd(u * 2 + 1, mid + 1, r, ql, qr, x);
    val[u] = max(val[u * 2], val[u * 2 + 1]);
}

long long query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return val[u];
    push(u);
    int       mid = (l + r) / 2;
    long long res = LLONG_MIN;
    if (ql <= mid)
        res = max(res, query(u * 2, l, mid, ql, qr));
    if (qr > mid)
        res = max(res, query(u * 2 + 1, mid + 1, r, ql, qr));
    return res;
}

void input() {
    scanf("%d%d", &n, &q);
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    val.resize(n * 4);
    tagAdd.resize(n * 4, 0);
    tagAssign.resize(n * 4, NO_ASSIGN);
}

void process() {
    build(1, 1, n);
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int       l, r;
            long long x;
            scanf("%d%d%lld", &l, &r, &x);
            updateAssign(1, 1, n, l, r, x);
        } else if (op == 2) {
            int       l, r;
            long long x;
            scanf("%d%d%lld", &l, &r, &x);
            updateAdd(1, 1, n, l, r, x);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, 1, n, l, r));
        }
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
