#include <bits/stdc++.h>
using namespace std;

int    h;
double tot, cur;

void input() { scanf("%d", &h); }

void process() {
    cur = h;
    for (int i = 0; i < 10; i++) {
        tot += cur;
        cur /= 2;
        if (i < 9)
            tot += cur;
    }
}

void output() { printf("%g\n%g\n", tot, cur); }

int main() {
    input();
    process();
    output();
    return 0;
}
