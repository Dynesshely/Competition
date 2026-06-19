#include <bits/stdc++.h>
using namespace std;

int n, k;

int digit(int n, int k) {
    for (int i = 1; i < k; i++)
        n /= 10;
    return n % 10;
}

void input() { scanf("%d%d", &n, &k); }

void process() { printf("%d\n", digit(n, k)); }

int main() {
    input();
    process();
    return 0;
}
