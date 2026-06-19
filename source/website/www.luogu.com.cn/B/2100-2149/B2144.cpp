#include <bits/stdc++.h>
using namespace std;

int m, n;

int ack(int m, int n) {
    if (m == 0)
        return n + 1;
    if (n == 0)
        return ack(m - 1, 1);
    return ack(m - 1, ack(m, n - 1));
}

void input() { scanf("%d%d", &m, &n); }

void process() { printf("%d\n", ack(m, n)); }

int main() {
    input();
    process();
    return 0;
}
