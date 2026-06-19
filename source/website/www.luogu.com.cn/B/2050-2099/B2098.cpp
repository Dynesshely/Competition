#include <bits/stdc++.h>
using namespace std;

int n, via[105], first;

void input() { scanf("%d", &n); }

void process() {
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (!via[x]) {
            via[x] = 1;
            if (first)
                printf(" ");
            printf("%d", x);
            first = 1;
        }
    }
    printf("\n");
}

int main() {
    input();
    process();
    return 0;
}
