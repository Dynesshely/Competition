#include <bits/stdc++.h>
using namespace std;

const int MAXN     = 100010;
const int MAXNODES = MAXN * 20;

struct Node {
    int  l, r;
    char val;
} tree[MAXNODES];

int nodeCnt;
int rootIdx[MAXN];
int lenAfterMod[MAXN];

int update(int prev, int l, int r, int pos, char val) {
    int cur     = ++nodeCnt;
    tree[cur].l = tree[prev].l;
    tree[cur].r = tree[prev].r;
    if (l == r) {
        tree[cur].val = val;
        return cur;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        tree[cur].l = update(tree[prev].l, l, mid, pos, val);
    else
        tree[cur].r = update(tree[prev].r, mid + 1, r, pos, val);
    return cur;
}

char query(int node, int l, int r, int pos) {
    if (l == r)
        return tree[node].val;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return query(tree[node].l, l, mid, pos);
    return query(tree[node].r, mid + 1, r, pos);
}

int main() {
    int n;
    scanf("%d", &n);
    int modCnt = 0, curLen = 0;
    rootIdx[0]     = 0;
    lenAfterMod[0] = 0;
    for (int i = 0; i < n; i++) {
        char op;
        scanf(" %c", &op);
        if (op == 'T') {
            char x;
            scanf(" %c", &x);
            curLen++;
            modCnt++;
            rootIdx[modCnt]     = update(rootIdx[modCnt - 1], 1, n, curLen, x);
            lenAfterMod[modCnt] = curLen;
        } else if (op == 'Q') {
            int x;
            scanf("%d", &x);
            printf("%c\n", query(rootIdx[modCnt], 1, n, x));
        } else {
            int x;
            scanf("%d", &x);
            int target = modCnt - x;
            modCnt++;
            rootIdx[modCnt]     = rootIdx[target];
            curLen              = lenAfterMod[target];
            lenAfterMod[modCnt] = curLen;
        }
    }
    return 0;
}
