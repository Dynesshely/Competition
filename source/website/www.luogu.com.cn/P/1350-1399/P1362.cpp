#include <bits/stdc++.h>
using namespace std;

int sumDig(long long x) {
    int s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

long long         L, R;
vector<long long> a;

void input() { scanf("%lld%lld", &L, &R); }

void process() {
    queue<long long> q;
    for (int d = 1; d <= 3; d++)
        q.push(d);
    while (!q.empty()) {
        long long cur = q.front();
        q.pop();
        if (sumDig(cur) * sumDig(cur) == sumDig(cur * cur))
            a.push_back(cur);
        for (int d = 0; d <= 3; d++) {
            long long nxt = cur * 10 + d;
            if (nxt <= 1000000000LL)
                q.push(nxt);
        }
    }
    sort(a.begin(), a.end());
}

void output() {
    int ans = upper_bound(a.begin(), a.end(), R) - lower_bound(a.begin(), a.end(), L);
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
