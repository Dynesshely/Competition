#include <bits/stdc++.h>
using namespace std;

int m, n, ans;

void input() { scanf("%d%d", &m, &n); }

void process() {
    ans = 0;
    for (int i = m; i <= n; i++)
        if (i % 17 == 0)
            ans += i;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
