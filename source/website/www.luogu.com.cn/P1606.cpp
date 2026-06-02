#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 35;
const int V = 905;
const int E = 800000;

int n, m, s, t;
int mp[N][N], id[N][N];

int head[V], to[E], nxt[E], ecnt;

int dis[V];
ll  cnt[V];

bool vis[N][N];
bool inq[V];

int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

void input();
void process();
void output();

inline void add(int, int);
inline bool chk(int, int);

void dfs(int, int, int);
void build();
void spfa();

int main() {
    input();
    process();
    output();
    return 0;
}

void input() {
    scanf("%d%d", &n, &m);

    memset(head, -1, sizeof(head));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mp[i][j]);

            id[i][j] = (i - 1) * m + j;

            if (mp[i][j] == 3)
                s = id[i][j];
            if (mp[i][j] == 4)
                t = id[i][j];
        }
    }
}

void process() {
    build();
    spfa();
}

void output() {
    if (dis[t] == 0x3f3f3f3f) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dis[t] - 1);
    printf("%lld\n", cnt[t]);
}

inline void add(int u, int v) {
    to[ecnt]  = v;
    nxt[ecnt] = head[u];
    head[u]   = ecnt++;
}

inline bool chk(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

void dfs(int rt, int x, int y) {
    if (mp[x][y] == 2 || mp[x][y] == 3)
        return;

    if (mp[x][y] == 0 || mp[x][y] == 4) {
        add(id[rt / m + 1][0], 0);
    }

    if (mp[x][y] == 0 || mp[x][y] == 4) {
        add(rt, id[x][y]);
        return;
    }

    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (!chk(nx, ny) || vis[nx][ny])
            continue;

        vis[nx][ny] = 1;
        dfs(rt, nx, ny);
    }
}

void build() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (mp[i][j] != 0 && mp[i][j] != 3)
                continue;

            memset(vis, 0, sizeof(vis));

            vis[i][j] = 1;

            int rt = id[i][j];

            for (int k = 0; k < 8; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (!chk(nx, ny) || vis[nx][ny])
                    continue;

                vis[nx][ny] = 1;
                dfs(rt, nx, ny);
            }
        }
    }
}

void spfa() {
    memset(dis, 0x3f, sizeof(dis));

    queue<int> q;

    dis[s] = 0;
    cnt[s] = 1;
    inq[s] = 1;

    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        inq[u] = 0;

        for (int i = head[u]; i != -1; i = nxt[i]) {
            int v = to[i];

            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                cnt[v] = cnt[u];

                if (!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            } else if (dis[v] == dis[u] + 1) {
                cnt[v] += cnt[u];

                if (!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}