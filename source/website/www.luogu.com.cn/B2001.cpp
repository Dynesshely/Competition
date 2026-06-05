#include <bits/stdc++.h>
using namespace std;

long long a, b;

void input() {
    scanf("%lld%lld", &a, &b);
}

void process() {
    a += b;
}

void output() {
    printf("%lld\n", a);
}

int main() {
    input();
    process();
    output();
    return 0;
}
