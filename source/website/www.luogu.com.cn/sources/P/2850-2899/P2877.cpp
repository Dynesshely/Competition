#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 9;

double low[N], high[N];
long long sumt[N], sump[N];

struct Cow {
    long long t, p;
    bool operator<(const Cow &o) const { return t * o.p > o.t * p; }
} cows[N];

int que[N];

bool chk(int i, int j, int k, int l) {
    return (cows[i].t - cows[j].t) * (cows[k].p - cows[l].p)
         > (cows[k].t - cows[l].t) * (cows[i].p - cows[j].p);
}

bool chk2(int i, int j, long long t, long long p) {
    return (cows[i].t - cows[j].t) * p > t * (cows[i].p - cows[j].p);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) scanf("%lld%lld", &cows[i].t, &cows[i].p);
        sort(cows + 1, cows + 1 + n);
        for (int i = 1; i <= n; ++i) {
            sumt[i] = sumt[i - 1] + cows[i].t;
            sump[i] = sump[i - 1] + cows[i].p;
        }
        int hd = 1, tl = 0;
        for (int i = 1; i <= n; ++i) {
            while (tl >= hd && cows[i].p >= cows[que[tl]].p) --tl;
            while (tl > hd && chk(que[tl], i, que[tl - 1], que[tl])) --tl;
            que[++tl] = i;
            while (hd < tl && chk2(que[hd], que[hd + 1], sumt[i], sump[i])) ++hd;
            int u = que[hd];
            low[i] = cows[u].t - (double)sumt[i] / sump[i] * cows[u].p;
        }
        int tp = 0;
        for (int i = n; i >= 1; --i) {
            while (tp > 0 && cows[i].p <= cows[que[tp]].p) --tp;
            while (tp > 1 && chk(i, que[tp], que[tp], que[tp - 1])) --tp;
            que[++tp] = i;
            while (tp > 1 && !chk2(que[tp], que[tp - 1], sumt[i - 1], sump[i - 1])) --tp;
            int u = que[tp];
            high[i] = cows[u].t - (double)sumt[i - 1] / sump[i - 1] * cows[u].p;
        }
        int ans = 0;
        for (int i = 1; i < n; ++i)
            if (high[i + 1] > low[i]) ++ans;
        printf("%d\n", ans);
        for (int i = n - 1; i >= 1; --i)
            if (high[i + 1] > low[i]) printf("%d\n", n - i);
    }
    return 0;
}
