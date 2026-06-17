#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int base = n / m, rem = n % m;
    for (int i = 0; i < m - rem; ++i) printf("%d ", base);
    for (int i = 0; i < rem; ++i) printf("%d ", base + 1);
    printf("\n");
    return 0;
}
