#include <bits/stdc++.h>
using namespace std;

int                 n, m, ta, tb, tc, td, a, h, e, r;
int                 probId[1005], stuId[1005];
map<int, int>       probIdx, stuIdx;
vector<vector<int>> cnt, maxSc, upd;
long long           trad, luogu;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &probId[i]);
        probIdx[probId[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &stuId[i]);
        stuIdx[stuId[i]] = i;
    }
    scanf("%d%d%d%d%d%d%d", &ta, &tb, &tc, &td, &a, &h, &e);
    scanf("%d", &r);
    cnt.assign(m, vector<int>(n, 0));
    maxSc.assign(m, vector<int>(n, 0));
    upd.assign(m, vector<int>(n, 0));
    for (int i = 0; i < r; i++) {
        int pr, sr, sc;
        scanf("%d%d%d", &pr, &sr, &sc);
        int pi = probIdx[pr], si = stuIdx[sr];
        cnt[si][pi]++;
        if (e && sc > maxSc[si][pi]) {
            upd[si][pi]++;
            maxSc[si][pi] = sc;
        }
    }
}

void process() {
    trad = 1LL * n * ta;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            int c = cnt[i][j];
            if (!c)
                continue;
            trad += min(1LL * tb * c, 1LL * ta + 1LL * tc * c);
            if (e)
                trad += 1LL * td * upd[i][j];
        }
    luogu = 1LL * n * ta + 1LL * r * tc;
    luogu = luogu * 100 / a + h;
}

void output() {
    printf("%lld\n%lld\n", trad, luogu);
    if (luogu < trad)
        printf("Use Luogu!\n");
    else
        printf("Forget it...\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
