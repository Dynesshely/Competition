#include <bits/stdc++.h>
using namespace std;

struct Garbage {
    int t, f, h;
};

int     D, G;
Garbage garb[105];
int     dp[200];

void input() {
    scanf("%d%d", &D, &G);
    for (int i = 0; i < G; i++)
        scanf("%d%d%d", &garb[i].t, &garb[i].f, &garb[i].h);
}

void process() {
    sort(garb, garb + G, [](Garbage a, Garbage b) { return a.t < b.t; });
    memset(dp, 0, sizeof(dp));
    dp[0] = 10;
    for (int i = 0; i < G; i++) {
        int t = garb[i].t, f = garb[i].f, h = garb[i].h;
        for (int j = D - 1; j >= 0; j--) {
            if (dp[j] >= t) {
                int life = dp[j];
                if (j + h >= D) {
                    printf("%d\n", t);
                    return;
                }
                dp[j + h] = max(dp[j + h], life);
                dp[j]     = life + f;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < D; i++)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
