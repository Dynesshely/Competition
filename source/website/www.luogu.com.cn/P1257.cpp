#include <bits/stdc++.h>
using namespace std;

int       n, x[10005], y[10005];
long long ans;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &x[i], &y[i]);
}

void process() {
    ans = 9e18;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            long long dx = x[i] - x[j], dy = y[i] - y[j];
            long long d = dx * dx + dy * dy;
            if (d < ans)
                ans = d;
        }
}

void output() { printf("%.4f\n", sqrt((double)ans)); }

int main() {
    input();
    process();
    output();
    return 0;
}
