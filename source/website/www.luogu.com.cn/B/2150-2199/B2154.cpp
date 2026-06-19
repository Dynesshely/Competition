#include <bits/stdc++.h>
using namespace std;

int n, ans;

void input() { scanf("%d", &n); }

int countOne(int x) {
    int cnt = 0;
    while (x) {
        if (x % 10 == 1)
            cnt++;
        x /= 10;
    }
    return cnt;
}

void process() {
    for (int i = 1; i <= n; i++)
        ans += countOne(i);
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
