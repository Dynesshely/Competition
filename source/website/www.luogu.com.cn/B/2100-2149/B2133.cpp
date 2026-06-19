#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

void process() {
    for (int total = 1;; total++) {
        int sum = total * (total + 1) / 2;
        if (sum > n) {
            int diff = sum - n;
            if (diff % 3 == 0) {
                int my = diff / 3;
                if (my >= 1 && my <= total) {
                    printf("%d %d\n", my, total);
                    return;
                }
            }
        }
    }
}

int main() {
    input();
    process();
    return 0;
}
