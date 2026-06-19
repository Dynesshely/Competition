#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int maxVal(int x, int y, int z) {
    int res = x;
    if (y > res)
        res = y;
    if (z > res)
        res = z;
    return res;
}

void input() { scanf("%d%d%d", &a, &b, &c); }

void process() {
    double m = (double)maxVal(a, b, c) / (maxVal(a + b, b, c) * maxVal(a, b, b + c));
    printf("%.3f\n", m);
}

int main() {
    input();
    process();
    return 0;
}
