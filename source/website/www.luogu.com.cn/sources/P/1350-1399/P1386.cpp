#include <bits/stdc++.h>
using namespace std;

int T, n, m, mod;
int fixedCnt[305];
int dp[305][305];
int C[305][305];

void input() {
    scanf("%d%d%d", &n, &m, &mod);
    memset(fixedCnt, 0, sizeof(fixedCnt));
    for (int i = 0; i < m; i++) {
        int p, q;
        scanf("%d%d", &p, &q);
        fixedCnt[q]++;
    }
}

void process() {
    int free      = n - m;
    int prefFixed = 0;
    for (int i = 1; i <= n; i++) {
        prefFixed += fixedCnt[i];
        if (prefFixed + free < i) {
            printf("NO\n");
            return;
        }
    }

    for (int i = 0; i <= free; i++) {
        C[i][0] = C[i][i] = 1 % mod;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0]  = 1;
    prefFixed = 0;

    for (int i = 1; i <= n; i++) {
        prefFixed += fixedCnt[i];
        for (int j = 0; j <= free; j++) {
            if (prefFixed + j < i)
                continue;
            long long sum = 0;
            for (int k = 0; k <= j; k++) {
                int rem = free - (j - k);
                sum     = (sum + (long long)dp[i - 1][j - k] * C[rem][k]) % mod;
            }
            dp[i][j] = sum;
        }
    }

    printf("YES %d\n", dp[n][free]);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        input();
        process();
    }
    return 0;
}
