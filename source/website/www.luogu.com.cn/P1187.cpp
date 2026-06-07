#include <bits/stdc++.h>
using namespace std;

int n, m, a[1005][1005];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        char s[1005];
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++)
            a[i][j] = s[j] - '0';
    }
}

void process() {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int ans  = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] > 0) {
                ans += 2;
                for (int k = 1; k <= a[i][j]; k++)
                    for (int d = 0; d < 4; d++)
                        if (a[i + dx[d]][j + dy[d]] < k)
                            ans++;
            }
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    return 0;
}
