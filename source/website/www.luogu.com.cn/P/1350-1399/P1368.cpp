#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

int n, a[MAXN];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void output() {
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        int cmp = a[(i + k) % n] - a[(j + k) % n];
        if (cmp == 0) {
            ++k;
        } else {
            if (cmp > 0)
                i = i + k + 1;
            else
                j = j + k + 1;
            if (i == j)
                ++j;
            k = 0;
        }
    }
    int beg = min(i, j);
    for (int p = 0; p < n; ++p) {
        printf("%d%c", a[(beg + p) % n], p == n - 1 ? '\n' : ' ');
    }
}

int main() {
    input();
    output();
    return 0;
}
