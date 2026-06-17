#include <bits/stdc++.h>
using namespace std;

long long a, b, p, ans;

void input() { scanf("%lld%lld%lld", &a, &b, &p); }

void process() {
    long long base = a % p, exp = b;
    ans = 1;
    while (exp) {
        if (exp & 1)
            ans = ans * base % p;
        base = base * base % p;
        exp >>= 1;
    }
}

void output() { printf("%lld^%lld mod %lld=%lld\n", a, b, p, ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
