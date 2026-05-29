#include <bits/stdc++.h>

bool squares[10000];

int main() {
    // Record all squares.
    for (int i = 2; i <= 36; ++i)
        squares[i * i] = true;

    for (int i = 1, p = i; i <= 9; ++i, p = i * i) {
        if (p < 10)
            continue;

        // printf("%d,%d\n", i, p);

        for (int j = 0; j <= 99; ++j) {
            int a = p / 10, b = p % 10;
            int c = j / 10, d = j % 10;

            // printf("%d %d %d %d\n", a, b, c, d);
            // continue;

            int index = a + b + c + d;

            if (squares[index]) {
                int result = p * 100 + j;

                printf("%d\n", result);

                // printf("%d - %d + %d + %d + %d = %d\n", result, a, b, c, d, index);
            }
        }
    }

    return 0;
}
