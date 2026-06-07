#include <bits/stdc++.h>
using namespace std;

const int MOD  = 100003;
const int MAXN = 1000;

int  n, m;
bool blocked[MAXN + 2][MAXN + 2];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        blocked[x][y] = true;
    }
}

void process() {
    if (n == 0) {
        printf("0\n");
        return;
    }
    int dp[MAXN + 2] = {0};
    dp[1]            = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (blocked[i][j]) {
                dp[j] = 0;
            } else {
                if (j > 1)
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }
    }
    printf("%d\n", dp[n]);
}

int main() {
    input();
    process();
    return 0;
}
