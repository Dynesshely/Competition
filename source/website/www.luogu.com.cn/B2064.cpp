#include <bits/stdc++.h>
using namespace std;

int n, a[35], maxA;
int fib[35];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > maxA)
            maxA = a[i];
    }
}

void process() {
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= maxA; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
}

void output() {
    for (int i = 0; i < n; i++)
        printf("%d\n", fib[a[i]]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
