#include <bits/stdc++.h>
using namespace std;

int a, b;

bool isPrime(int x) {
    if (x < 2)
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    scanf("%d%d", &a, &b);

    for (int p = 5; p <= 9; p += 2)
        if (p >= a && p <= b && isPrime(p))
            printf("%d\n", p);

    if (11 >= a && 11 <= b)
        printf("11\n");

    for (int d1 = 1; d1 <= 9; d1 += 2)
        for (int d2 = 0; d2 <= 9; d2++) {
            int pal = 100 * d1 + 10 * d2 + d1;
            if (pal > b)
                continue;
            if (pal >= a && isPrime(pal))
                printf("%d\n", pal);
        }

    for (int d1 = 1; d1 <= 9; d1 += 2)
        for (int d2 = 0; d2 <= 9; d2++)
            for (int d3 = 0; d3 <= 9; d3++) {
                int pal = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
                if (pal > b)
                    continue;
                if (pal >= a && isPrime(pal))
                    printf("%d\n", pal);
            }

    for (int d1 = 1; d1 <= 9; d1 += 2)
        for (int d2 = 0; d2 <= 9; d2++)
            for (int d3 = 0; d3 <= 9; d3++)
                for (int d4 = 0; d4 <= 9; d4++) {
                    int pal = 1000000 * d1 + 100000 * d2 + 10000 * d3 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
                    if (pal > b)
                        continue;
                    if (pal >= a && isPrime(pal))
                        printf("%d\n", pal);
                }

    return 0;
}
