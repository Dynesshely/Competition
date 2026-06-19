#include <bits/stdc++.h>
using namespace std;

int n, m, p[1005], bestPrice, maxProfit;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &p[i]);
}

void process() {
    sort(p, p + m);
    for (int i = 0; i < m; ++i) {
        int cnt    = min(n, m - i);
        int profit = p[i] * cnt;
        if (profit > maxProfit) {
            maxProfit = profit;
            bestPrice = p[i];
        }
    }
}

void output() { printf("%d %d\n", bestPrice, maxProfit); }

int main() {
    input();
    process();
    output();
    return 0;
}
