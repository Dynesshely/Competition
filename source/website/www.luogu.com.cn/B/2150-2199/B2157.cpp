#include <bits/stdc++.h>
using namespace std;

int    n;
double total;

void input() { scanf("%d", &n); }

void process() {
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        total += (x + 69) / 70 * 0.1;
    }
}

void output() { printf("%.1lf\n", total); }

int main() {
    input();
    process();
    output();
    return 0;
}
