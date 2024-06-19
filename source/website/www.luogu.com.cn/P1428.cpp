#include <bits/stdc++.h>
using namespace std;
int n, a[110];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        scanf("%d", &a[i]);
        for (int j = 1; j <= i; ++j)
            if (a[j] < a[i])
                sum++;
        printf("%d ", sum);
    }
    printf("\n");
    return 0;
}