#include <bits/stdc++.h>
using namespace std;
const int MAXV = 1000005;
int nxt[MAXV];
int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int op, x, y;
        scanf("%d%d", &op, &x);
        if (op == 1) {
            scanf("%d", &y);
            nxt[y] = nxt[x];
            nxt[x] = y;
        } else if (op == 2) {
            printf("%d\n", nxt[x]);
        } else {
            nxt[x] = nxt[nxt[x]];
        }
    }
    return 0;
}
