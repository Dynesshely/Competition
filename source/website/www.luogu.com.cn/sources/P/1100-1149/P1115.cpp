#include <bits/stdc++.h>
using namespace std;

const int maxN = 200005;
int       n, a[maxN];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void process() {
    int cur = a[0], ans = a[0];
    for (int i = 1; i < n; ++i) {
        cur = max(a[i], cur + a[i]);
        if (cur > ans)
            ans = cur;
    }
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
