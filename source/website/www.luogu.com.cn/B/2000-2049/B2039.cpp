#include <bits/stdc++.h>
using namespace std;

long long x, y;

void input() { scanf("%lld%lld", &x, &y); }

void process() {
    if (x > y)
        printf(">");
    else if (x == y)
        printf("=");
    else
        printf("<");
}

void output() { printf("\n"); }

int main() {
    input();
    process();
    output();
    return 0;
}
