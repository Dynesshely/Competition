#include <bits/stdc++.h>
using namespace std;

int n, sum;

void input() { scanf("%d", &n); }

void process() {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
        sum += fact;
    }
}

void output() { printf("%d\n", sum); }

int main() {
    input();
    process();
    output();
    return 0;
}
