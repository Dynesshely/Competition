#include <bits/stdc++.h>
using namespace std;

int l, r, ans;

void input() { scanf("%d%d", &l, &r); }

void process() {
    ans = 0;
    for (int i = l; i <= r; i++) {
        int x = i;
        while (x) {
            if (x % 10 == 2)
                ans++;
            x /= 10;
        }
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
