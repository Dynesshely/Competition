#include <bits/stdc++.h>
using namespace std;

int n, m;

void input() { scanf("%d%d", &n, &m); }

void process() {
    int p = 1;
    while (true) {
        int       r      = n - p + 1;
        long long maxInv = 1LL * (r - 1) * (r - 2) / 2;
        if (m > maxInv) {
            int k = m - maxInv;
            printf("%d ", p + k);
            for (int x = n; x > p + k; x--)
                printf("%d ", x);
            for (int x = p + k - 1; x >= p; x--)
                printf("%d%c", x, x == p ? '\n' : ' ');
            return;
        }
        printf("%d%c", p, p == n ? '\n' : ' ');
        p++;
        if (p > n)
            return;
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
