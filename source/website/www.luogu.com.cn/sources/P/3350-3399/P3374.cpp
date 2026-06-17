/*
    树状数组模板题 1
*/

#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;

const int n = 500005;
int       N, M, a[n], c[n];

int query(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ret += c[i];
    return ret;
}

void edit(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &a[i]), edit(i, a[i]);
    for (int i = 1; i <= M; ++i) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x, v;
            scanf("%d%d", &x, &v);
            edit(x, v);
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%d\n", query(y) - query(x - 1));
        }
    }
    return 0;
}