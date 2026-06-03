#include <bits/stdc++.h>
using namespace std;

int a, b, x, y, ans;

void input() {
    scanf("%d%d%d%d", &a, &b, &x, &y);
}

void process() {
    ans = abs(a - b);
    ans = min(ans, abs(a - x) + abs(y - b));
    ans = min(ans, abs(a - y) + abs(x - b));
}

void output() {
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
