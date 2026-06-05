#include <bits/stdc++.h>
using namespace std;

int         n;
int         cost[10010];
vector<int> pre[10010];
int         dp[10010];
int         ans;

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int id, t, d;
        scanf("%d%d", &id, &t);
        cost[id] = t;
        while (scanf("%d", &d) && d)
            pre[id].push_back(d);
    }
}

void process() {
    for (int i = 1; i <= n; i++) {
        int maxPre = 0;
        for (int j : pre[i])
            if (dp[j] > maxPre)
                maxPre = dp[j];
        dp[i] = maxPre + cost[i];
        if (dp[i] > ans)
            ans = dp[i];
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
