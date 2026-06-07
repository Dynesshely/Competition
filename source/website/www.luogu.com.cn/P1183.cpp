#include <bits/stdc++.h>
using namespace std;

int n, ans;
int x[105], y[105];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);
}

void process() {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        int j = i % n + 1;
        s += x[i] * y[j] - x[j] * y[i];
    }
    if (s < 0)
        s = -s;
    ans = s / 2;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
