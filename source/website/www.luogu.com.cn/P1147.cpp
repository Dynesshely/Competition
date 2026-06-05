#include <bits/stdc++.h>
using namespace std;

int M;

void input() { scanf("%d", &M); }

void process() {
    int lim = sqrt(2 * M);
    for (int k = lim; k >= 2; --k) {
        int numerator = M - k * (k - 1) / 2;
        if (numerator > 0 && numerator % k == 0) {
            int L = numerator / k;
            printf("%d %d\n", L, L + k - 1);
        }
    }
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
