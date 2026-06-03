#include <bits/stdc++.h>
using namespace std;

int n, a[10010];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

int process() {
    int ans = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i] == a[i - 1] + 1) cur++;
        else cur = 1;
        if (cur > ans) ans = cur;
    }
    return ans;
}

int main() {
    input();
    int ans = process();
    printf("%d", ans);
    return 0;
}
