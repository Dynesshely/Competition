#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int n, m, k, modVal, ans;
int grid[805][805];
int prevRow[805][16][2];
int curRow[805][16][2];

void input() {
    scanf("%d%d%d", &n, &m, &k);
    modVal = k + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &grid[i][j]);
}

void process() {
    ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            for (int d = 0; d < modVal; d++)
                curRow[j][d][0] = curRow[j][d][1] = 0;

        for (int j = 1; j <= m; j++) {
            int val           = grid[i][j];
            curRow[j][val][0] = (curRow[j][val][0] + 1) % MOD;

            for (int d = 0; d < modVal; d++) {
                int f0 = prevRow[j][d][0];
                if (f0) {
                    int nd           = (d - val + modVal) % modVal;
                    curRow[j][nd][1] = (curRow[j][nd][1] + f0) % MOD;
                }
                int f1 = prevRow[j][d][1];
                if (f1) {
                    int nd           = (d + val) % modVal;
                    curRow[j][nd][0] = (curRow[j][nd][0] + f1) % MOD;
                }
            }

            if (j > 1) {
                for (int d = 0; d < modVal; d++) {
                    int f0 = curRow[j - 1][d][0];
                    if (f0) {
                        int nd           = (d - val + modVal) % modVal;
                        curRow[j][nd][1] = (curRow[j][nd][1] + f0) % MOD;
                    }
                    int f1 = curRow[j - 1][d][1];
                    if (f1) {
                        int nd           = (d + val) % modVal;
                        curRow[j][nd][0] = (curRow[j][nd][0] + f1) % MOD;
                    }
                }
            }

            ans = (ans + curRow[j][0][1]) % MOD;
        }

        for (int j = 1; j <= m; j++)
            for (int d = 0; d < modVal; d++) {
                prevRow[j][d][0] = curRow[j][d][0];
                prevRow[j][d][1] = curRow[j][d][1];
            }
    }
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    process();
    output();
    return 0;
}
