#include <bits/stdc++.h>
using namespace std;

struct City {
    int h, id, prev, next;
} c[100005];

bool cmpCity(City x, City y) { return x.h < y.h; }

int pick(int a, int b, int i) {
    if (!a)
        return c[b].id;
    if (!b)
        return c[a].id;
    if (c[i].h - c[a].h <= c[b].h - c[i].h)
        return c[a].id;
    return c[b].id;
}

void del(int pos) {
    if (c[pos].next)
        c[c[pos].next].prev = c[pos].prev;
    if (c[pos].prev)
        c[c[pos].prev].next = c[pos].next;
}

int       n, t, pos[100005], nxtA[100005], nxtB[100005];
int       f[25][100005][2];
long long da[25][100005][2], db[25][100005][2], la, lb;

void calc(int s, long long x) {
    la = lb = 0;
    int k   = 0;
    for (int i = t; i >= 0; --i) {
        if (f[i][s][k] && da[i][s][k] + db[i][s][k] <= x) {
            x -= da[i][s][k] + db[i][s][k];
            la += da[i][s][k];
            lb += db[i][s][k];
            if (!i)
                k ^= 1;
            s = f[i][s][k];
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c[i].h);
        c[i].id = i;
    }
    sort(c + 1, c + 1 + n, cmpCity);
    for (int i = 1; i <= n; ++i) {
        pos[c[i].id] = i;
        c[i].prev    = i - 1;
        c[i].next    = i + 1;
    }
    c[1].prev = c[n].next = 0;
    for (int i = 1; i < n; ++i) {
        int p = pos[i], p1 = c[p].prev, p2 = c[p].next;
        if (p1 && (c[p].h - c[p1].h <= c[p2].h - c[p].h || !p2))
            nxtB[i] = c[p1].id, nxtA[i] = pick(c[p1].prev, p2, p);
        else
            nxtB[i] = c[p2].id, nxtA[i] = pick(p1, c[p2].next, p);
        del(p);
    }
    for (int i = 1; i <= n; ++i) {
        if (nxtA[i]) {
            f[0][i][0]  = nxtA[i];
            da[0][i][0] = abs(c[pos[i]].h - c[pos[nxtA[i]]].h);
            db[0][i][0] = 0;
        }
        if (nxtB[i]) {
            f[0][i][1]  = nxtB[i];
            da[0][i][1] = 0;
            db[0][i][1] = abs(c[pos[i]].h - c[pos[nxtB[i]]].h);
        }
    }
    t = (int)(log(1.0 * n) / log(2) + 1);
    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k <= 1; ++k) {
                int l = (i == 1) ? k ^ 1 : k;
                if (f[i - 1][j][k])
                    f[i][j][k] = f[i - 1][f[i - 1][j][k]][l];
                if (f[i][j][k]) {
                    da[i][j][k] = da[i - 1][j][k] + da[i - 1][f[i - 1][j][k]][l];
                    db[i][j][k] = db[i - 1][j][k] + db[i - 1][f[i - 1][j][k]][l];
                }
            }
        }
    }
    long long x;
    scanf("%lld", &x);
    int       p    = 0;
    long long ansa = 1, ansb = 0;
    for (int i = 1; i <= n; ++i) {
        calc(i, x);
        if (!lb)
            la = 1;
        if (la * ansb < lb * ansa || (la * ansb == lb * ansa && c[pos[i]].h > c[pos[p]].h))
            ansa = la, ansb = lb, p = i;
    }
    printf("%d\n", p);
    int m, s;
    scanf("%d", &m);
    while (m--) {
        scanf("%d%lld", &s, &x);
        calc(s, x);
        printf("%lld %lld\n", la, lb);
    }
    return 0;
}
