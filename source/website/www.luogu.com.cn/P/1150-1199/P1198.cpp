#include <bits/stdc++.h>
using namespace std;

int       m, d, len;
long long tree[800005];
long long lastAns;

void update(int node, int l, int r, int pos, long long val) {
    if (l == r) {
        tree[node] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        update(node << 1, l, mid, pos, val);
    else
        update(node << 1 | 1, mid + 1, r, pos, val);
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
}

long long query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return tree[node];
    int       mid = (l + r) >> 1;
    long long res = -1e18;
    if (ql <= mid)
        res = max(res, query(node << 1, l, mid, ql, qr));
    if (qr > mid)
        res = max(res, query(node << 1 | 1, mid + 1, r, ql, qr));
    return res;
}

int main() {
    scanf("%d%d", &m, &d);
    char      op[2];
    long long x;
    for (int i = 0; i < m; ++i) {
        scanf("%s%lld", op, &x);
        if (op[0] == 'A') {
            ++len;
            long long val = (x + lastAns) % d;
            if (val < 0)
                val += d;
            update(1, 1, m, len, val);
        } else {
            lastAns = query(1, 1, m, len - x + 1, len);
            printf("%lld\n", lastAns);
        }
    }
    return 0;
}
