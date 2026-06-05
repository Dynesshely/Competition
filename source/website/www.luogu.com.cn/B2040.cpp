#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

void process() {}

void output() {
    if (n >= 10 && n <= 99)
        printf("1\n");
    else
        printf("0\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
