#include <bits/stdc++.h>
using namespace std;

int n, k;

int dfs(int x) {
    if (x <= k)
        return 1;
    if ((x - k) & 1)
        return 1;
    return dfs((x + k) / 2) + dfs((x - k) / 2);
}

int main() {
    scanf("%d%d", &n, &k);
    printf("%d\n", dfs(n));
    return 0;
}
