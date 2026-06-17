#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i * i <= n; ++i)
        printf("%d ", i * i);
    printf("\n");
    return 0;
}
