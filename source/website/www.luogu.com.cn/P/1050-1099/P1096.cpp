#include <bits/stdc++.h>
using namespace std;

int a[100];

int main() {
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    a[0] = 1; int len = 1;
    for (int i = 0; i < n + 1; ++i) {
        int c = 0;
        for (int j = 0; j < len; ++j) { int t = a[j] * 2 + c; a[j] = t % 10; c = t / 10; }
        while (c) { a[len++] = c % 10; c /= 10; }
    }
    a[0] -= 2;
    for (int i = 0; a[i] < 0; ++i) { a[i] += 10; a[i + 1] -= 1; }
    while (len > 1 && a[len - 1] == 0) --len;
    for (int i = len - 1; i >= 0; --i) putchar('0' + a[i]);
    putchar('\n');
    return 0;
}
