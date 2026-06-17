#include <bits/stdc++.h>
using namespace std;

int  a, b, f;
char c;

void input() { scanf("%d %d %c %d", &a, &b, &c, &f); }

void process() {
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if (f == 1)
                putchar(c);
            else if (i == 0 || i == a - 1 || j == 0 || j == b - 1)
                putchar(c);
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

int main() {
    input();
    process();
    return 0;
}
