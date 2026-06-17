#include <bits/stdc++.h>
using namespace std;

int                                                              n;
priority_queue<long long, vector<long long>, greater<long long>> pq;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        pq.push(x);
    }
}

void process() {
    long long ans = 0;
    while (pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long sum = a + b;
        ans += sum;
        pq.push(sum);
    }
    printf("%lld\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
