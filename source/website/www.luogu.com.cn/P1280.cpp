#include <bits/stdc++.h>
using namespace std;

int         n, k;
vector<int> start[10005];
int         dp[10005];

void input() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++) {
        int p, t;
        scanf("%d%d", &p, &t);
        start[p].push_back(t);
    }
}

void process() {
    for (int i = n; i >= 1; i--) {
        if (start[i].empty())
            dp[i] = dp[i + 1] + 1;
        else
            for (int t : start[i])
                dp[i] = max(dp[i], dp[i + t]);
    }
}

void output() { printf("%d\n", dp[1]); }

int main() {
    input();
    process();
    output();
    return 0;
}
