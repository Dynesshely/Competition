#include <bits/stdc++.h>
using namespace std;

int m, n;

int maxPrimeFactor(int x) {
    int maxF = 1, tmp = x;
    for (int i = 2; i * i <= tmp; i++)
        while (tmp % i == 0) {
            maxF = i;
            tmp /= i;
        }
    if (tmp > 1)
        maxF = tmp;
    return maxF;
}

void input() { scanf("%d%d", &m, &n); }

void process() {
    for (int i = m; i <= n; i++) {
        printf("%d", maxPrimeFactor(i));
        if (i < n)
            printf(",");
    }
    printf("\n");
}

int main() {
    input();
    process();
    return 0;
}
