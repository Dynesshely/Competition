#include <bits/stdc++.h>
using namespace std;

int t[105], lis[105], lds[105];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
    for (int i = 0; i < n; ++i) {
        lis[i] = 1;
        for (int j = 0; j < i; ++j) if (t[j] < t[i]) lis[i] = max(lis[i], lis[j] + 1);
    }
    for (int i = n - 1; i >= 0; --i) {
        lds[i] = 1;
        for (int j = n - 1; j > i; --j) if (t[j] < t[i]) lds[i] = max(lds[i], lds[j] + 1);
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) mx = max(mx, lis[i] + lds[i] - 1);
    printf("%d\n", n - mx);
    return 0;
}
