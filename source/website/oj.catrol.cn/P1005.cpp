#include <bits/stdc++.h>

using namespace std;

int m, k, *a;

void input() {
    scanf("%d %d", &m, &k);
    a = new int[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
}

void process() {
    sort(a, a + m);
}

void output() {
    printf("%d\n", a[m - k]);
    delete[] a;
}

int main() {
    input();
    process();
    output();
    return 0;
}