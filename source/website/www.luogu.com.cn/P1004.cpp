#include <bits/stdc++.h>
using namespace std;

// P1004 [NOIP 2000 提高组] 方格取数
// 两人同时从 (1,1) 走到 (N,N)，各走一步，最大化收益
// dp[step][x1][x2] 其中 y1=step-x1, y2=step-x2

int main() {
    int N;
    scanf("%d", &N);
    vector a(N + 1, vector<int>(N + 1, 0));
    while (true) {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        if (x == 0 && y == 0 && v == 0) break;
        a[x][y] = v;
    }

    // dp[step][x1][x2], step range: 2..2N
    vector dp(2 * N + 1, vector(N + 1, vector<int>(N + 1, -1)));
    dp[2][1][1] = a[1][1];

    for (int s = 2; s < 2 * N; ++s) {
        for (int x1 = 1; x1 <= N && x1 <= s; ++x1) {
            int y1 = s - x1;
            if (y1 < 1 || y1 > N) continue;
            for (int x2 = 1; x2 <= N && x2 <= s; ++x2) {
                int y2 = s - x2;
                if (y2 < 1 || y2 > N) continue;
                if (dp[s][x1][x2] < 0) continue;

                for (int d1 = 0; d1 < 2; ++d1) {
                    int nx1 = x1 + d1, ny1 = y1 + (1 - d1);
                    if (nx1 < 1 || nx1 > N || ny1 < 1 || ny1 > N) continue;
                    for (int d2 = 0; d2 < 2; ++d2) {
                        int nx2 = x2 + d2, ny2 = y2 + (1 - d2);
                        if (nx2 < 1 || nx2 > N || ny2 < 1 || ny2 > N) continue;
                        int add = a[nx1][ny1];
                        if (nx1 != nx2 || ny1 != ny2) add += a[nx2][ny2];
                        dp[s + 1][nx1][nx2] = max(
                            dp[s + 1][nx1][nx2], dp[s][x1][x2] + add);
                    }
                }
            }
        }
    }

    printf("%d\n", max(0, dp[2 * N][N][N]));
    return 0;
}
