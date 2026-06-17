#include <bits/stdc++.h>
using namespace std;

int a, b, c, ans;

void input() { scanf("%d%d%d", &a, &b, &c); }

void process() { ans = (a + b) / c; }

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
