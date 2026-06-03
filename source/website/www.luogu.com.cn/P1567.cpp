#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int n, a[MAXN];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void process() {
    int ans = 1, cur = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1])
            ++cur;
        else
            cur = 1;
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
