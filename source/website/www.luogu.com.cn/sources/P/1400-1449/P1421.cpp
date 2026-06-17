#include <bits/stdc++.h>
using namespace std;

int a, b;

void input() { scanf("%d%d", &a, &b); }

void process() {
    int total = a * 10 + b;
    printf("%d\n", total / 19);
}

int main() {
    input();
    process();
    return 0;
}
