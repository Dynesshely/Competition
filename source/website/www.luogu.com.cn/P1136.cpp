#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int  n, k;
char s[505];
int  dp[101][101][2];
int  ndp[101][101][2];

void input() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
}

void process() {
    for (int a = 0; a <= k; a++)
        for (int b = 0; b <= k; b++)
            for (int l = 0; l < 2; l++)
                dp[a][b][l] = -INF;

    if (s[0] == 'j') {
        dp[0][0][0] = 0;
        if (k >= 1)
            dp[1][0][1] = 0;
    } else {
        if (k >= 1)
            dp[0][1][0] = 0;
        dp[0][0][1] = 0;
    }

    for (int pos = 1; pos < n; pos++) {
        for (int a = 0; a <= k; a++)
            for (int b = 0; b <= k; b++)
                for (int l = 0; l < 2; l++)
                    ndp[a][b][l] = -INF;

        for (int a = 0; a <= k; a++) {
            for (int b = 0; b <= k; b++) {
                for (int l = 0; l < 2; l++) {
                    int cur = dp[a][b][l];
                    if (cur < 0)
                        continue;

                    int na = a, nb = b;
                    if (s[pos] == 'z')
                        nb++;
                    if (na <= k && nb <= k)
                        if (cur > ndp[na][nb][0])
                            ndp[na][nb][0] = cur;

                    na = a;
                    nb = b;
                    if (s[pos] == 'j')
                        na++;
                    if (na <= k && nb <= k) {
                        int val = cur + (l == 0 ? 1 : 0);
                        if (val > ndp[na][nb][1])
                            ndp[na][nb][1] = val;
                    }
                }
            }
        }

        for (int a = 0; a <= k; a++)
            for (int b = 0; b <= k; b++)
                for (int l = 0; l < 2; l++)
                    dp[a][b][l] = ndp[a][b][l];
    }
}

void output() {
    int ans = 0;
    for (int a = 0; a <= k; a++) {
        if (dp[a][a][0] > ans)
            ans = dp[a][a][0];
        if (dp[a][a][1] > ans)
            ans = dp[a][a][1];
    }
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
