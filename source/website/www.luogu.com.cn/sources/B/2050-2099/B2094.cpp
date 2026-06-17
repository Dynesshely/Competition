#include <bits/stdc++.h>
using namespace std;

int n, a[105], mx = -2000000000, sum;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > mx)
            mx = a[i];
    }
}

void process() {
    for (int i = 0; i < n; i++)
        if (a[i] != mx)
            sum += a[i];
}

void output() { printf("%d\n", sum); }

int main() {
    input();
    process();
    output();
    return 0;
}
