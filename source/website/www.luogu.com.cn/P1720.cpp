#include <bits/stdc++.h>
using namespace std;

long long fib[55];

void input() {
    int n;
    scanf("%d", &n);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    printf("%lld.00\n", fib[n]);
}

int main() {
    input();
    return 0;
}
