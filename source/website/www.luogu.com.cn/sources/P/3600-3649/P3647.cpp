// APIO2014 连珠线
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
const int maxe = maxn * (maxn / 400);
int       u[maxe], v[maxe], w[maxe], first[maxe], ne[maxe], tot = 0;
void      add(int uu, int vv, int ww) {
    ++tot;
    u[tot] = uu, v[tot] = vv, w[tot] = ww;
    ne[tot]       = first[u[tot]];
    first[u[tot]] = tot;
}
int T, ans = 0, tu, tv, tw;
int main() {
    memset(first, -1, sizeof(first));
    scanf("%d", &T);
    for (int i = 1; i < T; ++i) {
        scanf("%d %d %d", &tu, &tv, &tw);
        add(tu, tv, tw);
        ans += tw;
    }
    printf("%d\n", ans);
    return 0;
}