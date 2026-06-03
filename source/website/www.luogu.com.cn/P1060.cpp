#include <cstdio>
#include <algorithm>
using namespace std;

int dp[30005];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int v, p;
        scanf("%d%d", &v, &p);
        int val = v * p;
        for (int j = n; j >= v; --j)
            if (dp[j - v] + val > dp[j])
                dp[j] = dp[j - v] + val;
    }
    printf("%d\n", dp[n]);
    return 0;
}
