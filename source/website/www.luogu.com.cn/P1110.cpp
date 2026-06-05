#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
const int INF  = 2000000005;

int           n, m;
int           first[MAXN], last[MAXN];
multiset<int> gapSet;
set<int>      sortVal;
int           minSortGap;

void input() {
    scanf("%d%d", &n, &m);
    minSortGap = INF;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        first[i] = last[i] = x;
    }
    for (int i = 1; i < n; i++)
        gapSet.insert(abs(first[i] - first[i + 1]));
    for (int i = 1; i <= n; i++) {
        auto res = sortVal.insert(first[i]);
        if (!res.second)
            minSortGap = 0;
    }
    if (minSortGap != 0) {
        int prev = -1;
        for (int x : sortVal) {
            if (prev != -1)
                minSortGap = min(minSortGap, x - prev);
            prev = x;
        }
    }
}

void insert(int pos, int k) {
    int prevLast = last[pos];
    if (pos < n) {
        int nextFirst = first[pos + 1];
        gapSet.erase(gapSet.find(abs(prevLast - nextFirst)));
        gapSet.insert(abs(k - nextFirst));
    }
    gapSet.insert(abs(prevLast - k));
    last[pos] = k;

    auto res = sortVal.insert(k);
    if (!res.second)
        minSortGap = 0;
    else if (minSortGap != 0) {
        auto it = res.first;
        if (it != sortVal.begin())
            minSortGap = min(minSortGap, k - *prev(it));
        auto nxt = next(it);
        if (nxt != sortVal.end())
            minSortGap = min(minSortGap, *nxt - k);
    }
}

void process() {
    char op[15];
    while (m--) {
        scanf("%s", op);
        if (op[0] == 'I') {
            int i, k;
            scanf("%d%d", &i, &k);
            insert(i, k);
        } else if (op[4] == 'G')
            printf("%d\n", *gapSet.begin());
        else
            printf("%d\n", minSortGap);
    }
}

int main() {
    input();
    process();
    return 0;
}
