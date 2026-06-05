#include <bits/stdc++.h>
using namespace std;

int a, b, c, mx;

void input() { scanf("%d%d%d", &a, &b, &c); }

void process() {
    mx = a;
    if (b > mx)
        mx = b;
    if (c > mx)
        mx = c;
}

void output() { printf("%d\n", mx); }

int main() {
    input();
    process();
    output();
    return 0;
}
