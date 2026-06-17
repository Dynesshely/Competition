#include <bits/stdc++.h>
using namespace std;

int       n, a[5005], dp[5005];
long long cnt[5005];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
}

void process() {
    for (int i = 1; i <= n; i++) {
        dp[i]  = 1;
        cnt[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] > a[i]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i]  = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }
        for (int j = 1; j < i; j++) {
            if (a[j] == a[i] && dp[j] == dp[i])
                cnt[j] = 0;
        }
    }
    int       mx    = 0;
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > mx) {
            mx    = dp[i];
            total = cnt[i];
        } else if (dp[i] == mx) {
            total += cnt[i];
        }
    }
    printf("%d %lld\n", mx, total);
}

int main() {
    input();
    process();
    return 0;
}
