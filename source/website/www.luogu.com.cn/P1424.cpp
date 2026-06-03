#include <bits/stdc++.h>
using namespace std;

int x, n;

void input() {
    scanf("%d%d", &x, &n);
}

void process() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = (x + i - 1) % 7 + 1;
        if (cur <= 5) ans += 250;
    }
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
