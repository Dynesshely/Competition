#include <bits/stdc++.h>
using namespace std;

int n, a[105];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
}

void process() {
    int ans = 0, cur = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] == a[i - 1])
            ++cur;
        else
            ans = max(ans, cur), cur = 1;
    ans = max(ans, cur);
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
