#include <bits/stdc++.h>
using namespace std;

struct farmer {
    int price, amount;
};

bool cmp(farmer a, farmer b) { return a.price < b.price; }

int    n, m;
farmer farmers[5005];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d", &farmers[i].price, &farmers[i].amount);
}

void process() { sort(farmers, farmers + m, cmp); }

void output() {
    long long ans    = 0;
    int       remain = n;
    for (int i = 0; i < m && remain > 0; i++) {
        int buy = min(remain, farmers[i].amount);
        ans += 1LL * buy * farmers[i].price;
        remain -= buy;
    }
    printf("%lld\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
