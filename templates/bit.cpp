#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

int tree[MAXN], n;

void add(int x, int v) {
    for (int i = x; i <= n; i += i & -i)
        tree[i] += v;
}

int sum(int x) {
    int r = 0;
    for (int i = x; i > 0; i -= i & -i)
        r += tree[i];
    return r;
}

int query(int l, int r) { return sum(r) - sum(l - 1); }

void build(int a[]) {
    for (int i = 1; i <= n; ++i)
        tree[i] = 0;
    for (int i = 1; i <= n; ++i)
        add(i, a[i]);
}

void rangeAdd(int l, int r, int v) {
    add(l, v);
    add(r + 1, -v);
}
