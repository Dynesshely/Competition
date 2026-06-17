#include <bits/stdc++.h>
using namespace std;

int n, r, ans;

int calcPow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void input() { scanf("%d%d", &n, &r); }

void process() {
    int c[11][11] = {0};
    for (int i = 0; i <= r; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    for (int i = 0; i <= r; i++) {
        int term = c[r][i] * calcPow(r - i, n);
        if (i & 1)
            ans -= term;
        else
            ans += term;
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
