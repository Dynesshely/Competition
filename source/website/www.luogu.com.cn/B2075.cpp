#include <bits/stdc++.h>
using namespace std;

int a, b, res;

void input() { scanf("%d%d", &a, &b); }

void process() {
    res = 1;
    for (int i = 0; i < b; i++)
        res = res * a % 1000;
}

void output() { printf("%03d\n", res); }

int main() {
    input();
    process();
    output();
    return 0;
}
