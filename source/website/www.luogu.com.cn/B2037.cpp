#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

void process() {}

void output() {
    if (n & 1)
        printf("odd\n");
    else
        printf("even\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
