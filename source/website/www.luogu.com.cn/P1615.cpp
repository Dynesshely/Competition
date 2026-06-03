#include <bits/stdc++.h>
using namespace std;

int h1, m1, s1, h2, m2, s2, n;

void input() {
    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);
    scanf("%d", &n);
}

void process() {
    long long t1 = 1LL * h1 * 3600 + m1 * 60 + s1;
    long long t2 = 1LL * h2 * 3600 + m2 * 60 + s2;
    printf("%lld\n", (t2 - t1) * n);
}

int main() {
    input();
    process();
    return 0;
}
