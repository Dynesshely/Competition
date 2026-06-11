#include <bits/stdc++.h>
using namespace std;

int  n, cnt[155], dis[155];
char name[155][35];

void input() {
    n = 0;
    while (scanf("%d%d%s", &cnt[n], &dis[n], name[n]) == 3)
        n++;
}

void process() {
    int       bestIdx  = 0;
    long long bestCost = 1LL << 60;
    for (int i = 0; i < n; i++) {
        long long cost = 0;
        for (int j = 0; j < n; j++)
            cost += 1LL * cnt[j] * abs(dis[i] - dis[j]);
        if (cost < bestCost || (cost == bestCost && dis[i] < dis[bestIdx])) {
            bestCost = cost;
            bestIdx  = i;
        }
    }
    printf("%s %lld\n", name[bestIdx], bestCost);
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
