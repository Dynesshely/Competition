#include <bits/stdc++.h>
using namespace std;

int n, m, a[100005];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
}

void process() {
    int ans = 1, cur = 0;
    for (int i = 1; i <= n; ++i) {
        if (cur + a[i] > m) {
            ++ans;
            cur = a[i];
        } else
            cur += a[i];
    }
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
