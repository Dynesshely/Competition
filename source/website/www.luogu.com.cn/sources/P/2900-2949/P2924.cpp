#include <bits/stdc++.h>
using namespace std;

const int N = 260, INF = 0x3f3f3f3f;

struct Pt {
    int x, y;
} pts[N];

struct Edge {
    int fr, to, dx, dy;
} edges[N * N];

int n, m, best[N], dp[N][N];

int cross(int ax, int ay, int bx, int by) { return ax * by - bx * ay; }

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &pts[i].x, &pts[i].y);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j) {
                ++m;
                edges[m].fr = i;
                edges[m].to = j;
                edges[m].dx = pts[j].x - pts[i].x;
                edges[m].dy = pts[j].y - pts[i].y;
            }
    sort(edges + 1, edges + m + 1, [](const Edge &a, const Edge &b) { return cross(a.dx, a.dy, b.dx, b.dy) < 0; });
    int ans = 0;
    for (int s = 1; s <= n; ++s) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
            best[i] = -INF;
        best[s] = 0;
        for (int k = 1; k <= m; ++k) {
            int u = edges[k].fr, v = edges[k].to;
            dp[u][v] = max(dp[u][v], best[u] + 1);
            if (v != s)
                best[v] = max(best[v], best[u] + 1);
        }
        for (int i = 1; i <= n; ++i)
            ans = max(ans, dp[i][s]);
    }
    printf("%d\n", ans);
    return 0;
}
