#include <bits/stdc++.h>
using namespace std;

int n, g, s, b, sumG, sumS, sumB;

void input() { scanf("%d", &n); }

void process() {
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &g, &s, &b);
        sumG += g;
        sumS += s;
        sumB += b;
    }
}

void output() { printf("%d %d %d %d\n", sumG, sumS, sumB, sumG + sumS + sumB); }

int main() {
    input();
    process();
    output();
    return 0;
}
