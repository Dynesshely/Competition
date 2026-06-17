#include <bits/stdc++.h>
using namespace std;

int n, a[25];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void process() {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n && a[i] != 0; ++i)
        ++cnt1;
    for (int i = n - 1; i >= 0 && a[i] != 0; --i)
        ++cnt2;
    if (cnt1 % 2 == 1 || cnt2 % 2 == 1)
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    input();
    process();
    return 0;
}
