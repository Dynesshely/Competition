#include <bits/stdc++.h>
using namespace std;

int n, a[55], L, R;
int tot, deficit, excess;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    scanf("%d%d", &L, &R);
}

void process() {
    tot = 0;
    for (int i = 0; i < n; ++i)
        tot += a[i];
    int mn = n * L, mx = n * R;
    if (tot < mn || tot > mx) {
        printf("-1\n");
        return;
    }
    deficit = 0;
    excess  = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < L)
            deficit += L - a[i];
        if (a[i] > R)
            excess += a[i] - R;
    }
    printf("%d\n", max(deficit, excess));
}

void output() {}

int main() {
    input();
    process();
    output();
    return 0;
}
