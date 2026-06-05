#include <bits/stdc++.h>
using namespace std;

int n, a, ans;

void input() { scanf("%d", &n); }

void process() {
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        int u  = a % 10;
        int t  = a / 10 % 10;
        int h  = a / 100 % 10;
        int th = a / 1000;
        if (u - th - h - t > 0)
            ++ans;
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
