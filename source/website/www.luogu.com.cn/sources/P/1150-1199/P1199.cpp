#include <bits/stdc++.h>
using namespace std;

int n, a[505][505], ans;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        a[i][i] = -1;
        for (int j = i + 1; j < n; ++j) {
            scanf("%d", &a[i][j]);
            a[j][i] = a[i][j];
        }
    }
}

void process() {
    ans = 0;
    for (int i = 0; i < n; ++i) {
        int max1 = 0, max2 = 0;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] > max1) {
                max2 = max1;
                max1 = a[i][j];
            } else if (a[i][j] > max2)
                max2 = a[i][j];
        }
        if (max2 > ans)
            ans = max2;
    }
}

void output() { printf("1\n%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
