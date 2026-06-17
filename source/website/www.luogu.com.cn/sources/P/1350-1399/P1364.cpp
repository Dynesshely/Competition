#include <bits/stdc++.h>
using namespace std;

int         n, w[105];
vector<int> g[105];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d%d%d", &w[i], &u, &v);
        if (u) {
            g[i].push_back(u);
            g[u].push_back(i);
        }
        if (v) {
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }
}

int bfs(int s) {
    int dist[105];
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    int sum = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        sum += dist[u] * w[u];
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return sum;
}

int process() {
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
        ans = min(ans, bfs(i));
    return ans;
}

int main() {
    input();
    printf("%d\n", process());
    return 0;
}
