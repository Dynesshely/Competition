#include <bits/stdc++.h>
using namespace std;

int              n;
vector<int>      sums;
set<vector<int>> sols;

void check(int p) {
    int a0 = sums[0] + sums[1] - sums[p];
    if (a0 & 1)
        return;
    a0 /= 2;
    if (a0 < 0)
        return;

    int a1 = sums[0] - a0;
    int a2 = sums[1] - a0;
    if (a0 > a1 || a1 > a2)
        return;

    map<int, int> cnt;
    for (int x : sums)
        cnt[x]++;

    cnt[sums[0]]--;
    if (cnt[sums[0]] == 0)
        cnt.erase(sums[0]);
    cnt[sums[1]]--;
    if (cnt[sums[1]] == 0)
        cnt.erase(sums[1]);
    cnt[sums[p]]--;
    if (cnt[sums[p]] == 0)
        cnt.erase(sums[p]);

    vector<int> a = {a0, a1, a2};

    for (int k = 3; k < n; k++) {
        if (cnt.empty())
            return;
        int cur = cnt.begin()->first;
        int ak  = cur - a0;
        if (ak < a.back())
            return;

        a.push_back(ak);

        cnt[cur]--;
        if (cnt[cur] == 0)
            cnt.erase(cur);

        for (int i = 1; i < k; i++) {
            int  val = a[i] + ak;
            auto it  = cnt.find(val);
            if (it == cnt.end())
                return;
            it->second--;
            if (it->second == 0)
                cnt.erase(it);
        }
    }

    if (!cnt.empty())
        return;

    sols.insert(a);
}

void process() {
    int m = n * (n - 1) / 2;
    sums.resize(m);
    for (int i = 0; i < m; i++)
        scanf("%d", &sums[i]);
    sort(sums.begin(), sums.end());

    sols.clear();
    for (int p = 0; p < m && sols.size() <= 1; p++)
        check(p);
}

void output() {
    if (sols.size() == 1) {
        auto &a = *sols.begin();
        for (int i = 0; i < n; i++) {
            if (i)
                putchar(' ');
            printf("%d", a[i]);
        }
        putchar('\n');
    } else
        printf("Impossible\n");
}

int main() {
    while (scanf("%d", &n) == 1)
        process(), output();
    return 0;
}
