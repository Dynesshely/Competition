#include <bits/stdc++.h>
using namespace std;

int n, a[105];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void process() {
    for (int i = 0; i < n / 2; ++i)
        swap(a[i], a[n - 1 - i]);
}

void output() {
    for (int i = 0; i < n; ++i) {
        printf("%d", a[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
