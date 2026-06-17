#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int tot = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        cur = cur + a + b - 8;
        tot += cur;
    }
    printf("%d\n", tot);
    return 0;
}
