#include <bits/stdc++.h>
using namespace std;

int         s, t;
int         adj[24][2], cnt;
int         dist[1 << 16], parent[1 << 16], moveIdx[1 << 16];
vector<int> path;

int encode(char board[4][5]) {
    int state = 0;
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            if (board[r][c] == '1')
                state |= 1 << (r * 4 + c);
    return state;
}

void input() {
    char start[4][5], target[4][5];
    for (int i = 0; i < 4; i++)
        scanf("%s", start[i]);
    for (int i = 0; i < 4; i++)
        scanf("%s", target[i]);
    s   = encode(start);
    t   = encode(target);
    cnt = 0;
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 3; c++) {
            adj[cnt][0] = r * 4 + c;
            adj[cnt][1] = r * 4 + c + 1;
            cnt++;
        }
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 4; c++) {
            adj[cnt][0] = r * 4 + c;
            adj[cnt][1] = (r + 1) * 4 + c;
            cnt++;
        }
}

void process() {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[s]   = 0;
    parent[s] = -1;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == t)
            break;
        for (int i = 0; i < cnt; i++) {
            int u = adj[i][0], v = adj[i][1];
            if (((cur >> u) & 1) != ((cur >> v) & 1)) {
                int nxt = cur ^ (1 << u) ^ (1 << v);
                if (dist[nxt] == -1) {
                    dist[nxt]    = dist[cur] + 1;
                    parent[nxt]  = cur;
                    moveIdx[nxt] = i;
                    q.push(nxt);
                }
            }
        }
    }
    for (int cur = t; cur != s; cur = parent[cur])
        path.push_back(moveIdx[cur]);
    reverse(path.begin(), path.end());
}

void output() {
    printf("%d\n", (int)path.size());
    for (int m : path) {
        int u = adj[m][0], v = adj[m][1];
        printf("%d%d%d%d\n", u / 4 + 1, u % 4 + 1, v / 4 + 1, v % 4 + 1);
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
