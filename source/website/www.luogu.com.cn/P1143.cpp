#include <bits/stdc++.h>
using namespace std;

int  n, m;
char s[35];
char ans[35];

int charToInt(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

char intToChar(int x) {
    if (x < 10)
        return x + '0';
    return x - 10 + 'A';
}

void input() { scanf("%d%s%d", &n, s, &m); }

void process() {
    int       len = strlen(s);
    long long dec = 0;
    for (int i = 0; i < len; i++) {
        dec = dec * n + charToInt(s[i]);
    }
    if (dec == 0) {
        ans[0] = '0';
        ans[1] = '\0';
        return;
    }
    int pos = 0;
    while (dec > 0) {
        ans[pos++] = intToChar(dec % m);
        dec /= m;
    }
    ans[pos] = '\0';
    reverse(ans, ans + pos);
}

void output() { printf("%s\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
