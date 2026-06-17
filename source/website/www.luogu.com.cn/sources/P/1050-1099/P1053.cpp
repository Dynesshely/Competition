#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50005;
int adj[MAXN][2];
int target[MAXN];     // target[i] = student at position i
int target_pos[MAXN]; // target_pos[student] = position in target circle
int cnt[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &adj[i][0], &adj[i][1]);

    // Build target circle starting from student 1
    target[0] = 1;
    target[1] = adj[1][0]; // pick first neighbor as next
    int cur = target[1], prev = 1;
    for (int i = 2; i < n; ++i) {
        int nxt;
        if (adj[cur][0] == prev) nxt = adj[cur][1];
        else if (adj[cur][1] == prev) nxt = adj[cur][0];
        else { printf("-1\n"); return 0; }
        target[i] = nxt;
        prev = cur;
        cur = nxt;
    }
    // Check last connects back to first
    if (!(adj[cur][0] == target[0] || adj[cur][1] == target[0])) {
        printf("-1\n"); return 0;
    }
    // Verify all students distinct
    int seen[MAXN] = {0};
    for (int i = 0; i < n; ++i) {
        if (seen[target[i]]) { printf("-1\n"); return 0; }
        seen[target[i]] = 1;
    }

    for (int i = 0; i < n; ++i)
        target_pos[target[i]] = i;

    // Same direction: offset = (target_pos - initial_pos) % n
    memset(cnt, 0, sizeof(int) * (n + 1));
    for (int i = 0; i < n; ++i) {
        int d = (target_pos[i + 1] - i + n) % n;
        ++cnt[d];
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) if (cnt[i] > mx) mx = cnt[i];

    // Opposite direction
    memset(cnt, 0, sizeof(int) * (n + 1));
    for (int i = 0; i < n; ++i) {
        int d = (target_pos[i + 1] - (n - 1 - i) + n) % n;
        ++cnt[d];
    }
    for (int i = 0; i < n; ++i) if (cnt[i] > mx) mx = cnt[i];

    printf("%d\n", n - mx);
    return 0;
}
