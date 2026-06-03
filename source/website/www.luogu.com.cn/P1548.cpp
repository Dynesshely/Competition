#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int totalRect = n * (n + 1) / 2 * m * (m + 1) / 2;
    int squares = 0;
    int limit = min(n, m);
    for (int k = 1; k <= limit; ++k)
        squares += (n - k + 1) * (m - k + 1);
    printf("%d %d\n", squares, totalRect - squares);
    return 0;
}
