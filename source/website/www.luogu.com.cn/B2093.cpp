#include <bits/stdc++.h>
using namespace std;

int n, x, a[10010];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &x);
}

void process() {
    int ans = -1;
    for (int i = 0; i < n; ++i)
        if (a[i] == x) {
            ans = i;
            break;
        }
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
