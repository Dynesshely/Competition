#include <bits/stdc++.h>
using namespace std;

int a, n, res;

void input() { scanf("%d%d", &a, &n); }

void process() {
    res = 1;
    for (int i = 1; i <= n; i++)
        res *= a;
}

void output() { printf("%d\n", res); }

int main() {
    input();
    process();
    output();
    return 0;
}
