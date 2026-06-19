#include <bits/stdc++.h>
using namespace std;

int n;

bool isPrime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

bool isPalin(int x) {
    int rev = 0, tmp = x;
    while (tmp) {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    return rev == x;
}

void input() { scanf("%d", &n); }

void process() {
    int cnt = 0;
    for (int i = 11; i <= n; i++)
        if (isPrime(i) && isPalin(i))
            cnt++;
    printf("%d\n", cnt);
}

int main() {
    input();
    process();
    return 0;
}
