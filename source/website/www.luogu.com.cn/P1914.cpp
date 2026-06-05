#include <bits/stdc++.h>
using namespace std;

int  n;
char s[55];

void input() { scanf("%d%s", &n, s); }

void process() {
    n %= 26;
    for (int i = 0; s[i]; i++)
        s[i] = (s[i] - 'a' + n) % 26 + 'a';
}

void output() { printf("%s\n", s); }

int main() {
    input();
    process();
    output();
    return 0;
}
