#include <bits/stdc++.h>
using namespace std;

int n, ans;

bool has7(int x) {
    while (x) {
        if (x % 10 == 7)
            return true;
        x /= 10;
    }
    return false;
}

void input() { scanf("%d", &n); }

void process() {
    for (int i = 1; i <= n; ++i)
        if (i % 7 != 0 && !has7(i))
            ans += i * i;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
