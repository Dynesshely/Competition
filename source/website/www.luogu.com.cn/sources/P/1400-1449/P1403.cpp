#include <bits/stdc++.h>
using namespace std;

int       n;
long long ans;

void input() { scanf("%d", &n); }

void process() {
    ans = 0;
    for (int i = 1; i <= n; i++)
        ans += n / i;
}

void output() { printf("%lld\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
