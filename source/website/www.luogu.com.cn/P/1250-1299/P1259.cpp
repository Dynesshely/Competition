#include <bits/stdc++.h>
using namespace std;

int  n, pos;
char s[210];

void output() { printf("%s\n", s); }

void move(int p) {
    swap(s[p], s[pos]);
    swap(s[p + 1], s[pos + 1]);
    pos = p;
    output();
}

void process(int cur) {
    if (cur == 4) {
        move(3);
        move(7);
        move(1);
        move(6);
        move(0);
        return;
    }
    move(cur - 1);
    move(2 * cur - 2);
    process(cur - 1);
}

void input() { scanf("%d", &n); }

int main() {
    input();
    for (int i = 0; i < n; i++)
        s[i] = 'o';
    for (int i = n; i < 2 * n; i++)
        s[i] = '*';
    s[2 * n] = s[2 * n + 1] = '-';
    s[2 * n + 2]            = '\0';
    pos                     = 2 * n;
    output();
    process(n);
    return 0;
}
