#include <bits/stdc++.h>
using namespace std;

int n, a[1005], b[1005], ans;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
}

void process() {
    ans = 0;
    for (int i = 0; i < n; ++i)
        ans += a[i] * b[i];
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
