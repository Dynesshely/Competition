#include <bits/stdc++.h>
using namespace std;

int  m;
char n[1005];

void input() { scanf("%d%s", &m, n); }

void process() {
    int  len   = strlen(n);
    bool first = true;
    for (int i = 0; i < len; i++) {
        if (n[i] != '0') {
            if (!first)
                putchar('+');
            printf("%c*%d^%d", n[i], m, len - i - 1);
            first = false;
        }
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
