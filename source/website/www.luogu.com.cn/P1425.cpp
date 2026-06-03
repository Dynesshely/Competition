#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int start = a * 60 + b;
    int end = c * 60 + d;
    int diff = end - start;
    int h = diff / 60;
    int m = diff % 60;
    printf("%d %d\n", h, m);
    return 0;
}
