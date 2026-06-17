#include <bits/stdc++.h>
using namespace std;

int n, a[1005], ans;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void process() {
    ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ++ans;
            }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
}
