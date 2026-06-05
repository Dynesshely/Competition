#include <bits/stdc++.h>
using namespace std;

int n, a[100010];

int main() {
    scanf("%d", &n);
    int maxF = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > maxF)
            maxF = a[i];
    }
    sort(a, a + n);
    int uniqueF = unique(a, a + n) - a;
    int ans     = maxF * 6 + maxF * 4 + uniqueF * 5 + n;
    printf("%d\n", ans);
    return 0;
}
