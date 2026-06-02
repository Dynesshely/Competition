#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[105], b[105];
bool stone[20005];
int dp[20005];

int main() {
    int L, S, T, M;
    scanf("%d%d%d%d", &L, &S, &T, &M);
    for (int i = 1; i <= M; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + M + 1);
    if (S == T) {
        int ans = 0;
        for (int i = 1; i <= M; ++i)
            if (a[i] % S == 0) ++ans;
        printf("%d\n", ans);
        return 0;
    }
    int threshold = S * T;
    b[1] = min(a[1], threshold);
    for (int i = 2; i <= M; ++i)
        b[i] = b[i - 1] + min(a[i] - a[i - 1], threshold);
    int compressedL = b[M] + min(L - a[M], threshold);
    memset(stone, 0, sizeof(stone));
    for (int i = 1; i <= M; ++i) stone[b[i]] = true;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < compressedL; ++i) {
        if (dp[i] == 0x3f3f3f3f) continue;
        for (int j = S; j <= T; ++j) {
            int nxt = i + j;
            if (nxt >= compressedL) {
                if (dp[i] < ans) ans = dp[i];
            } else {
                int add = stone[nxt] ? 1 : 0;
                if (dp[i] + add < dp[nxt])
                    dp[nxt] = dp[i] + add;
            }
        }
    }
    // Also consider the case where compressedL itself is reachable (with stone)
    if (dp[compressedL] < ans) ans = dp[compressedL];
    printf("%d\n", ans);
    return 0;
}
