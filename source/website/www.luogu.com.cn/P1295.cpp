#include <bits/stdc++.h>
using namespace std;

int                 n, m;
vector<int>         h;
vector<long long>   dp;
deque<int>          q;
multiset<long long> vals;

void input() {
    scanf("%d%d", &n, &m);
    h.resize(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
}

void process() {
    dp.resize(n + 1);
    dp[0] = 0;
    vector<long long> S(n + 1, 0);
    for (int i = 1; i <= n; i++)
        S[i] = S[i - 1] + h[i];
    int L = 0;
    for (int i = 1; i <= n; i++) {
        while (S[i] - S[L] > m)
            L++;
        while (!q.empty() && q.front() < L) {
            if (q.size() >= 2)
                vals.erase(vals.find(dp[q[0]] + h[q[1]]));
            q.pop_front();
        }
        while (!q.empty() && h[q.back()] <= h[i]) {
            int back = q.back();
            q.pop_back();
            if (!q.empty())
                vals.erase(vals.find(dp[q.back()] + h[back]));
        }
        if (!q.empty())
            vals.insert(dp[q.back()] + h[i]);
        q.push_back(i);
        long long cur = vals.empty() ? LLONG_MAX : *vals.begin();
        if (q.front() > L)
            cur = min(cur, dp[L] + h[q.front()]);
        dp[i] = cur;
    }
}

void output() { printf("%lld\n", dp[n]); }

int main() {
    input();
    process();
    output();
    return 0;
}
