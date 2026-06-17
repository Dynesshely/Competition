#include <bits/stdc++.h>
using namespace std;

const int maxN = 15;

int     n, m, K;
int     a[maxN + 5][8];
char    s[maxN + 5];
mt19937 rnd(time(0));

int calc(int st, int x, int c, int t) { return ((a[st][(c << 2) | (t << 1)] + 1LL) * x + a[st][(c << 2) | (t << 1) | 1]) % m; }

bool isEnd(int st) { return st > (n - 1) << 1; }

bool isHome(int x) { return (x <= K) || (-x + m <= K); }

bool check(int st, int x, int c) {
    int t = rnd() & 1;
    if (isEnd(st))
        return isHome(x);
    if (st & 1)
        return check(st + 1, x, t) || check(st + 1, x, !t);
    return check(st + 1, calc(st >> 1, x, c, t), t) && check(st + 1, calc(st >> 1, x, c, !t), !t);
}

void input() {
    scanf("%d%d%d", &n, &m, &K);
    scanf("%s", s);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 8; ++j)
            scanf("%d", &a[i][j]);
}

void process() {
    int x = 0;
    for (int i = 0; i < n; ++i)
        if (check(i << 1, x, 1)) {
            putchar('B');
            x = calc(i, x, 1, s[i] == 'B');
        } else {
            putchar('T');
            x = calc(i, x, 0, s[i] == 'B');
        }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
