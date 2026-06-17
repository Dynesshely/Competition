#include <bits/stdc++.h>
using namespace std;

int a[105], n, m, nxt, tot, mx, cur, curCnt;

void doCalc() {
    nxt = tot = mx = 0;
    for (int i = 2; i <= m; ++i) {
        if (a[i] <= 0)
            continue;
        if (!nxt)
            nxt = i;
        tot += a[i];
        if (!mx || a[i] > a[mx])
            mx = i;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    doCalc();
    int least = max(a[mx] - (tot - a[mx]), tot % 2);
    if (a[1] <= least) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n%d\n", a[1] - least);
    while (a[mx] > curCnt + tot - a[mx]) {
        printf("1\n");
        --a[1];
        cur = 1;
        ++curCnt;
    }
    if ((curCnt + tot) % 2) {
        printf("1\n");
        --a[1];
        cur = 1;
        ++curCnt;
    }
    while (tot) {
        if (curCnt) {
            if (a[mx] > curCnt + tot - a[mx] - 2) {
                printf("%d\n", mx);
                --a[mx];
            } else {
                printf("%d\n", nxt);
                --a[nxt];
            }
            --curCnt;
            if (!curCnt)
                cur = 0;
        } else {
            cur    = nxt;
            curCnt = a[nxt];
            while (a[nxt]--)
                printf("%d\n", nxt);
        }
        doCalc();
        if (tot == a[mx] && (!curCnt || cur == 1))
            break;
    }
    while (a[1]--)
        printf("1\n");
    while (a[nxt]--)
        printf("%d\n", nxt);
    return 0;
}
