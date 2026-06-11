#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40005;

int         m, n;
int         a[205][205];
int         hId[205][205], vId[205][205];
int         hCnt, vCnt;
vector<int> adj[MAXN];
int         ml[MAXN], mr[MAXN], d[MAXN];

bool bfs() {
    queue<int> q;
    for (int h = 1; h <= hCnt; h++) {
        if (ml[h] == -1) {
            d[h] = 0;
            q.push(h);
        } else {
            d[h] = -1;
        }
    }
    bool ok = false;
    while (!q.empty()) {
        int h = q.front();
        q.pop();
        for (int v : adj[h]) {
            int nh = mr[v];
            if (nh != -1 && d[nh] == -1) {
                d[nh] = d[h] + 1;
                q.push(nh);
            } else if (nh == -1) {
                ok = true;
            }
        }
    }
    return ok;
}

bool dfs(int h) {
    for (int v : adj[h]) {
        int nh = mr[v];
        if (nh == -1 || (d[nh] == d[h] + 1 && dfs(nh))) {
            ml[h] = v;
            mr[v] = h;
            return true;
        }
    }
    d[h] = -1;
    return false;
}

void input() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void process() {
    hCnt = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 2)
                continue;
            hCnt++;
            while (j < n && a[i][j] != 2) {
                hId[i][j] = hCnt;
                j++;
            }
        }

    vCnt = 0;
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m; i++) {
            if (a[i][j] == 2)
                continue;
            vCnt++;
            while (i < m && a[i][j] != 2) {
                vId[i][j] = vCnt;
                i++;
            }
        }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0)
                adj[hId[i][j]].push_back(vId[i][j]);

    memset(ml, -1, sizeof(ml));
    memset(mr, -1, sizeof(mr));
    while (bfs())
        for (int h = 1; h <= hCnt; h++)
            if (ml[h] == -1)
                dfs(h);
}

void output() {
    int ans = 0;
    for (int h = 1; h <= hCnt; h++)
        if (ml[h] != -1)
            ans++;
    printf("%d\n", ans);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0 && mr[vId[i][j]] == hId[i][j])
                printf("%d %d\n", i + 1, j + 1);
}

int main() {
    input();
    process();
    output();
    return 0;
}
