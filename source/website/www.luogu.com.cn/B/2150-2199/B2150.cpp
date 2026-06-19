#include <bits/stdc++.h>
using namespace std;

int a;

void input() { scanf("%d", &a); }

void process() {
    if (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0))
        printf("Y\n");
    else
        printf("N\n");
}

void output() {}

int main() {
    input();
    process();
    return 0;
}
