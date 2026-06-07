#include <bits/stdc++.h>
using namespace std;

const int MOD = 504;

int len[205], f[205][205];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    int cols = 2 * n - 1;
    if (k > cols) {
        printf("0\n");
        return 0;
    }

    for (int i = 1; i <= cols; i++)
        if (i & 1)
            len[i] = i;
        else
            len[i] = i - 1;

    for (int i = 0; i <= cols; i++)
        f[i][0] = 1;

    for (int i = 1; i <= cols; i++)
        for (int j = 1; j <= k && j <= len[i]; j++)
            f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * (len[i] - j + 1)) % MOD;

    printf("%d\n", f[cols][k]);
    return 0;
}
