#include <bits/stdc++.h>
using namespace std;

int         n, m, ans;
vector<int> g[10005];
int         col[10005];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

bool process() {
    memset(col, -1, sizeof(col));
    for (int s = 1; s <= n; ++s) {
        if (col[s] != -1)
            continue;
        col[s] = 0;
        queue<int> q;
        q.push(s);
        int  cnt[2] = {1, 0};
        bool ok     = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (col[v] == -1) {
                    col[v] = col[u] ^ 1;
                    ++cnt[col[v]];
                    q.push(v);
                } else if (col[v] == col[u]) {
                    ok = false;
                }
            }
        }
        if (!ok)
            return false;
        ans += min(cnt[0], cnt[1]);
    }
    return true;
}

void output() { printf("%d\n", ans); }

int main() {
    input();
    if (!process())
        printf("Impossible\n");
    else
        output();
    return 0;
}
