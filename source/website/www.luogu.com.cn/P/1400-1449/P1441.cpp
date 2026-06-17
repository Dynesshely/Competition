#include <bits/stdc++.h>
using namespace std;

int  n, m, a[25];
bool removed[25];
int  ans;

void dfs(int pos, int cnt) {
    if (cnt == m) {
        bitset<2010> dp;
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            if (!removed[i])
                dp = dp | (dp << a[i]);
        int cur = dp.count() - 1;
        if (cur > ans)
            ans = cur;
        return;
    }
    if (pos == n)
        return;
    if (n - pos + cnt < m)
        return;
    removed[pos] = true;
    dfs(pos + 1, cnt + 1);
    removed[pos] = false;
    dfs(pos + 1, cnt);
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void process() { dfs(0, 0); }

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
