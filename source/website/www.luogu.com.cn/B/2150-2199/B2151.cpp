#include <bits/stdc++.h>
using namespace std;

int n, ans, cur;

void input() { scanf("%d", &n); }

void process() {
    for (int i = 0; i < n; i++) {
        int s, d;
        scanf("%d%d", &s, &d);
        if (s >= 90 && s <= 140 && d >= 60 && d <= 90)
            cur++;
        else {
            if (cur > ans)
                ans = cur;
            cur = 0;
        }
    }
    if (cur > ans)
        ans = cur;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
