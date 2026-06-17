#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

void process() {}

void output() {
    if (n <= 2)
        printf("0\n");
    else
        printf("%d\n", n - 2);
}

int main() {
    input();
    process();
    output();
    return 0;
}
