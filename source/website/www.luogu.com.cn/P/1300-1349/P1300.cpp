#include <bits/stdc++.h>
using namespace std;

int  h, w;
char g[35][35];
int  sr, sc, sd, fr, fc;
int  dr[4] = {-1, 0, 1, 0};
int  dc[4] = {0, 1, 0, -1};
int  dis[35][35][4];
int  inf = 0x3f3f3f3f;

struct Sta {
    int  r, c, d, w;
    bool operator>(const Sta &o) const { return w > o.w; }
};

int rd(int r, int c) { return r >= 0 && r < h && c >= 0 && c < w && g[r][c] != '.'; }

void input() {
    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", g[i]);
        for (int j = 0; j < w; j++) {
            if (g[i][j] == 'E') {
                sr = i;
                sc = j;
                sd = 1;
            }
            if (g[i][j] == 'W') {
                sr = i;
                sc = j;
                sd = 3;
            }
            if (g[i][j] == 'N') {
                sr = i;
                sc = j;
                sd = 0;
            }
            if (g[i][j] == 'S') {
                sr = i;
                sc = j;
                sd = 2;
            }
            if (g[i][j] == 'F') {
                fr = i;
                fc = j;
            }
        }
    }
}

void process() {
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<Sta, vector<Sta>, greater<Sta>> pq;
    dis[sr][sc][sd] = 0;
    pq.push({sr, sc, sd, 0});
    while (!pq.empty()) {
        Sta cur = pq.top();
        pq.pop();
        int r = cur.r, c = cur.c, d = cur.d, w = cur.w;
        if (w != dis[r][c][d])
            continue;
        bool blk[4];
        for (int nd = 0; nd < 4; nd++)
            blk[nd] = !rd(r + dr[nd], c + dc[nd]);
        for (int nd = 0; nd < 4; nd++) {
            if (nd == (d + 2) % 4 && (!blk[d] || !blk[(d + 3) % 4] || !blk[(d + 1) % 4]))
                continue;
            if (blk[nd])
                continue;
            int tc;
            if (nd == d)
                tc = 0;
            else if (nd == (d + 3) % 4)
                tc = 1;
            else if (nd == (d + 1) % 4)
                tc = 5;
            else
                tc = 10;
            int nr = r + dr[nd], nc = c + dc[nd], nw = w + tc;
            if (nw < dis[nr][nc][nd]) {
                dis[nr][nc][nd] = nw;
                pq.push({nr, nc, nd, nw});
            }
        }
    }
}

void output() {
    int ans = inf;
    for (int d = 0; d < 4; d++)
        ans = min(ans, dis[fr][fc][d]);
    printf("%d\n", ans);
}

int main() {
    input();
    process();
    output();
    return 0;
}
