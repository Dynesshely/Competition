#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void process() { sort(a, a + n); }

void output() {
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
