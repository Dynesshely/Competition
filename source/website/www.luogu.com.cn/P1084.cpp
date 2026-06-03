#include <bits/stdc++.h>
using namespace std;

const int N = 6e4;

int                  n, m, t, tot, aTot, bTot, cTot;
int                  d[N], query[N], f[N][20];
int                  ver[2 * N], edge[2 * N], nxt[2 * N], head[N];
bool                 ok, sta[N], need[N];
long long            ans, tim[N], ned[N], dist[N][20];
pair<long long, int> h[N];
queue<int>           q;

void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot; }

void bfs() {
    q.push(1);
    d[1] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            if (d[y])
                continue;
            d[y]    = d[x] + 1;
            f[y][0] = x, dist[y][0] = edge[i];
            for (int j = 1; j <= t; ++j) {
                f[y][j]    = f[f[y][j - 1]][j - 1];
                dist[y][j] = dist[y][j - 1] + dist[f[y][j - 1]][j - 1];
            }
            q.push(y);
        }
    }
}

bool dfs(int x) {
    bool hasSon = false;
    if (sta[x])
        return true;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (d[y] < d[x])
            continue;
        hasSon = true;
        if (!dfs(y))
            return false;
    }
    if (!hasSon)
        return false;
    return true;
}

bool check(long long lim) {
    memset(sta, 0, sizeof(sta));
    memset(tim, 0, sizeof(tim));
    memset(ned, 0, sizeof(ned));
    memset(h, 0, sizeof(h));
    memset(need, 0, sizeof(need));
    aTot = bTot = cTot = 0;
    for (int i = 1; i <= m; ++i) {
        long long x = query[i], cnt = 0;
        for (int j = t; j >= 0; --j)
            if (f[x][j] > 1 && cnt + dist[x][j] <= lim) {
                cnt += dist[x][j];
                x = f[x][j];
            }
        if (f[x][0] == 1 && cnt + dist[x][0] <= lim)
            h[++cTot] = {lim - cnt - dist[x][0], x};
        else
            sta[x] = true;
    }
    for (int i = head[1]; i; i = nxt[i])
        if (!dfs(ver[i]))
            need[ver[i]] = true;
    sort(h + 1, h + cTot + 1);
    for (int i = 1; i <= cTot; ++i)
        if (need[h[i].second] && h[i].first < dist[h[i].second][0])
            need[h[i].second] = false;
        else
            tim[++aTot] = h[i].first;
    for (int i = head[1]; i; i = nxt[i])
        if (need[ver[i]])
            ned[++bTot] = dist[ver[i]][0];
    if (aTot < bTot)
        return false;
    sort(tim + 1, tim + aTot + 1);
    sort(ned + 1, ned + bTot + 1);
    int i = 1, j = 1;
    while (i <= bTot && j <= aTot)
        if (tim[j] >= ned[i]) {
            ++i;
            ++j;
        } else
            ++j;
    return i > bTot;
}

int main() {
    long long l = 0, r = 0, mid;
    scanf("%d", &n);
    t = log2(n) + 1;
    for (int i = 1; i < n; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
        r += z;
    }
    bfs();
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &query[i]);
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            r   = mid - 1;
            ans = mid;
            ok  = true;
        } else
            l = mid + 1;
    }
    if (!ok)
        printf("-1");
    else
        printf("%lld", ans);
    return 0;
}
