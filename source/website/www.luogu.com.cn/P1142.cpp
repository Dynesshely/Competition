#include <bits/stdc++.h>
using namespace std;

int n, ans;
int x[705], y[705];

int input() {
    if (scanf("%d", &n) != 1)
        return 0;
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    return 1;
}

void process() {
    ans = n < 2 ? n : 2;
    for (int i = 0; i < n; ++i) {
        map<pair<int, int>, int> cnt;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];
            int g  = __gcd(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            ans = max(ans, ++cnt[{dx, dy}] + 1);
        }
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
