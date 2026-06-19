#include <bits/stdc++.h>
using namespace std;

int n;

int doSum(int x) {
    if (x == 1)
        return 1;
    return x + doSum(x - 1);
}

void input() { scanf("%d", &n); }

void process() { printf("%d\n", doSum(n)); }

int main() {
    input();
    process();
    return 0;
}
