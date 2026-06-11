#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int       n, m, k, D[MAXN], last[MAXN], off[MAXN];
int       arrive[MAXN], pref[MAXN], nxt[MAXN + 2];
long long sumT, ans;

void input() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i < n; i++)
        scanf("%d", &D[i]);
    for (int i = 0; i < m; i++) {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        sumT += t;
        if (t > last[a])
            last[a] = t;
        off[b]++;
    }
}

void process() {
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + off[i];
    pref[n + 1] = pref[n];
    for (int i = 2; i <= n; i++)
        arrive[i] = max(arrive[i - 1], last[i - 1]) + D[i - 1];
    long long initSum = 0;
    for (int i = 1; i <= n; i++)
        initSum += (long long)off[i] * arrive[i];
    long long reduce = 0;
    for (int t = 0; t < k; t++) {
        nxt[n + 1] = n + 1;
        for (int i = n; i >= 1; i--) {
            if (arrive[i] <= last[i])
                nxt[i] = i;
            else
                nxt[i] = nxt[i + 1];
        }
        int maxBenefit = 0, bestSeg = 0;
        for (int i = 1; i < n; i++) {
            if (D[i] == 0)
                continue;
            int limit   = nxt[i + 1];
            int benefit = pref[limit] - pref[i];
            if (benefit > maxBenefit) {
                maxBenefit = benefit;
                bestSeg    = i;
            }
        }
        if (maxBenefit == 0)
            break;
        D[bestSeg]--;
        reduce += maxBenefit;
        for (int i = bestSeg + 1; i <= n; i++)
            arrive[i] = max(arrive[i - 1], last[i - 1]) + D[i - 1];
    }
    ans = initSum - sumT - reduce;
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
