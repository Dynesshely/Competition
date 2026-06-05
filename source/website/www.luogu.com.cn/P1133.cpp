#include <bits/stdc++.h>
using namespace std;

int n, val[100005][3];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &val[i][0], &val[i][1], &val[i][2]);
}

int process() {
    int ans = 0;
    for (int p = 0; p < 2; p++) {
        for (int s = 0; s < 3; s++) {
            int dp[3] = {-1000000000, -1000000000, -1000000000};
            dp[s]     = val[1][s];
            for (int i = 2; i <= n; i++) {
                int ndp[3] = {-1000000000, -1000000000, -1000000000};
                int q      = (p + i) & 1;
                for (int hc = 0; hc < 3; hc++) {
                    for (int hp = 0; hp < 3; hp++) {
                        if (dp[hp] == -1000000000)
                            continue;
                        if (q) {
                            if (hc > hp)
                                ndp[hc] = max(ndp[hc], dp[hp] + val[i][hc]);
                        } else {
                            if (hc < hp)
                                ndp[hc] = max(ndp[hc], dp[hp] + val[i][hc]);
                        }
                    }
                }
                for (int j = 0; j < 3; j++)
                    dp[j] = ndp[j];
            }
            for (int t = 0; t < 3; t++) {
                if (dp[t] == -1000000000)
                    continue;
                if ((p == 0 && s > t) || (p == 1 && s < t))
                    ans = max(ans, dp[t]);
            }
        }
    }
    return ans;
}

void output() { printf("%d\n", process()); }

int main() {
    input();
    output();
    return 0;
}
