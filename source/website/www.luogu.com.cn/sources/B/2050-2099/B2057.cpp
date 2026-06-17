#include <bits/stdc++.h>
using namespace std;

int n, x, ans;

void input() { scanf("%d", &n); }

void process() {
    ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x > ans)
            ans = x;
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
