#include <bits/stdc++.h>
using namespace std;

int a1, a2, n, d, ans;

void input() { scanf("%d%d%d", &a1, &a2, &n); }

void process() {
    d   = a2 - a1;
    ans = a1 + (n - 1) * d;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
