#include <bits/stdc++.h>
using namespace std;

int m, n, a, cnt;

void input() { scanf("%d%d", &m, &n); }

void process() {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a > m)
            cnt++;
        else
            m -= a;
    }
}

void output() { printf("%d\n", cnt); }

int main() {
    input();
    process();
    output();
    return 0;
}
