#include <bits/stdc++.h>

int A = 0, B = 0, s = 10000, e = 99999;

int main() {

    for (int i = s; i <= e; ++i) {
        A = i * 10 + 7;
        B = i + 7 * 100000;
        if (B == A * 5) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
