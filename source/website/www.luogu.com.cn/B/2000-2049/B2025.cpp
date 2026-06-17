#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    for (int i = 0; i < n; i++) {
        int sp = abs(n / 2 - i);
        int st = n - 2 * sp;
        for (int j = 0; j < sp; j++)
            putchar(' ');
        for (int j = 0; j < st; j++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
