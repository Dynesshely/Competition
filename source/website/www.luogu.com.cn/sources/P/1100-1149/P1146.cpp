#include <bits/stdc++.h>
using namespace std;

int n;

void input() { scanf("%d", &n); }

void process() {}

void output() {
    printf("%d\n", n);
    for (int k = 1; k <= n; ++k) {
        for (int c = 0; c < n; ++c) {
            if (c < k)
                printf("%d", (k - 1) & 1);
            else
                printf("%d", k & 1);
        }
        printf("\n");
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
