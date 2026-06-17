#include <bits/stdc++.h>
using namespace std;

struct Platform {
    int h, l, r;
};

const int MAXN = 1005;
int       n;
Platform  p[MAXN];
int       leftFall[MAXN], rightFall[MAXN];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &p[i].h, &p[i].l, &p[i].r);
}

void process() {
    for (int i = 1; i <= n; ++i) {
        int bestLeft = 0, bestRight = 0;
        int bestHLeft = -1, bestHRight = -1;
        for (int j = 1; j <= n; ++j) {
            if (p[j].h >= p[i].h)
                continue;
            if (p[j].l < p[i].l && p[i].l < p[j].r) {
                if (p[j].h > bestHLeft || (p[j].h == bestHLeft && j < bestLeft)) {
                    bestHLeft = p[j].h;
                    bestLeft  = j;
                }
            }
            if (p[j].l < p[i].r && p[i].r < p[j].r) {
                if (p[j].h > bestHRight || (p[j].h == bestHRight && j < bestRight)) {
                    bestHRight = p[j].h;
                    bestRight  = j;
                }
            }
        }
        leftFall[i]  = bestLeft;
        rightFall[i] = bestRight;
    }
}

void output() {
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", leftFall[i], rightFall[i]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
