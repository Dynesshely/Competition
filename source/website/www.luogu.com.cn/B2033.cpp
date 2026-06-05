#include <bits/stdc++.h>
using namespace std;

int       a, b;
long long ans;

void input() { scanf("%d%d", &a, &b); }

void process() { ans = 1ll * a * b; }

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
