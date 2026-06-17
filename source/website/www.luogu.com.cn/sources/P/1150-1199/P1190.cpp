#include <bits/stdc++.h>
using namespace std;

int n, m, w[10005];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
}

void process() {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < m; i++)
        pq.push(w[i]);
    for (int i = m; i < n; i++) {
        int t = pq.top();
        pq.pop();
        pq.push(t + w[i]);
    }
    int ans = 0;
    while (!pq.empty()) {
        ans = pq.top();
        pq.pop();
    }
    printf("%d", ans);
}

int main() {
    input();
    process();
    return 0;
}
