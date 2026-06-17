#include <bits/stdc++.h>
using namespace std;

int  n, k;
int  a[10005];
bool dp[105], nd[105];

void input() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void process() {
    for (int i = 0; i < k; ++i)
        dp[i] = false;
    dp[(a[0] % k + k) % k] = true;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j)
            nd[j] = false;
        for (int j = 0; j < k; ++j)
            if (dp[j]) {
                nd[((j + a[i]) % k + k) % k] = true;
                nd[((j - a[i]) % k + k) % k] = true;
            }
        for (int j = 0; j < k; ++j)
            dp[j] = nd[j];
    }
}

void output() {
    if (dp[0])
        printf("Divisible\n");
    else
        printf("Not divisible\n");
}

int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        input();
        process();
        output();
    }
    return 0;
}
