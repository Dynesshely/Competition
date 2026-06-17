#include <bits/stdc++.h>
using namespace std;

const int N = 11810;
const int M = 23007;

struct Node {
    int x, y, d;
};

int n, m;
int g[20][20];

int h[2][M], q[2][N], cnt[2];
int v[2][M];

bool vis[20][20];

int ans;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

void input();
void process();
void output();

inline int  pos(int, int);
inline void ins(int, int, int);
inline int  get(int, int);
inline int  add(int, int);

int solve1();
int solve2();

int main() {
    input();
    process();
    output();
    return 0;
}

void input() {
    scanf("%d%d", &n, &m);

    n += 2;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = 1;

    for (int i = 2; i <= n - 1; i++)
        g[i][2] = g[2][i] = 0;

    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x + 2][y + 2] = 0;
    }

    for (int i = 1; i <= n / 2; i++) {
        int t[20];
        memcpy(t, g[i], sizeof g[i]);
        memcpy(g[i], g[n - i + 1], sizeof g[i]);
        memcpy(g[n - i + 1], t, sizeof t);
    }
}

void process() { ans = solve1() - solve2(); }

void output() { printf("%d\n", ans); }

inline int pos(int cur, int s) {
    int t = s % M;

    while (h[cur][t] != -1 && h[cur][t] != s) {
        if (++t == M)
            t = 0;
    }

    return t;
}

inline void ins(int cur, int s, int w) {
    int t = pos(cur, s);

    if (h[cur][t] == -1) {
        h[cur][t]          = s;
        v[cur][t]          = w;
        q[cur][++cnt[cur]] = t;
    } else
        v[cur][t] = max(v[cur][t], w);
}

inline int get(int s, int k) { return (s >> (k << 1)) & 3; }

inline int add(int k, int x) { return x << (k << 1); }

int solve1() {
    int res = -1000000000;
    int cur = 0;

    memset(h, -1, sizeof h);

    ins(cur, 0, 1);

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= cnt[cur]; j++)
            h[cur][q[cur][j]] <<= 2;

        for (int j = 1; j <= n; j++) {

            int lst = cur;

            cur ^= 1;
            cnt[cur] = 0;

            memset(h[cur], -1, sizeof h[cur]);

            for (int k = 1; k <= cnt[lst]; k++) {

                int s = h[lst][q[lst][k]];
                int w = v[lst][q[lst][k]];

                int l = get(s, j - 1);
                int r = get(s, j);

                if (!g[i][j]) {
                    ins(cur, s, w);
                } else if (!l && !r) {

                    ins(cur, s, w);

                    if (g[i + 1][j] && g[i][j + 1])
                        ins(cur, s + add(j - 1, 1) + add(j, 2), w + 1);
                } else if (!l && r) {

                    if (g[i][j + 1])
                        ins(cur, s, w + 1);

                    if (g[i + 1][j])
                        ins(cur, s - add(j, r) + add(j - 1, r), w + 1);
                } else if (l && !r) {

                    if (g[i + 1][j])
                        ins(cur, s, w + 1);

                    if (g[i][j + 1])
                        ins(cur, s - add(j - 1, l) + add(j, l), w + 1);
                } else if (l == 1 && r == 1) {

                    for (int u = j + 1, c = 1;; u++) {

                        int z = get(s, u);

                        if (z == 1)
                            c++;
                        else if (z == 2) {

                            if (--c == 0) {
                                ins(cur, s - add(j, r) - add(j - 1, l) - add(u, 1), w + 1);
                                break;
                            }
                        }
                    }
                } else if (l == 2 && r == 2) {

                    for (int u = j - 2, c = 1;; u--) {

                        int z = get(s, u);

                        if (z == 2)
                            c++;
                        else if (z == 1) {

                            if (--c == 0) {
                                ins(cur, s - add(j, r) - add(j - 1, l) + add(u, 1), w + 1);
                                break;
                            }
                        }
                    }
                } else if (l == 2 && r == 1) {

                    ins(cur, s - add(j - 1, l) - add(j, r), w + 1);
                } else if (i == n && j == n) {

                    res = max(res, w);
                }
            }
        }
    }

    return res - 2 * n - 1;
}

int solve2() {

    memset(vis, 0, sizeof vis);

    queue<Node> q;

    q.push({1, 3, 1});

    while (!q.empty()) {

        Node t = q.front();
        q.pop();

        int x = t.x;
        int y = t.y;
        int d = t.d;

        if (x == n - 2 && y == n)
            return d;

        vis[x][y] = 1;

        for (int i = 0; i < 4; i++) {

            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 1 || xx > n - 2 || yy < 3 || yy > n)
                continue;

            if (!g[xx][yy] || vis[xx][yy])
                continue;

            q.push({xx, yy, d + 1});
        }
    }

    return 0;
}
