#include <bits/stdc++.h>
using namespace std;

int                    n, m;
vector<pair<int, int>> g[1001];
int                    dist[1001];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[b].push_back({a, c});
    }
}

bool process() {
    for (int i = 1; i <= n; i++)
        dist[i] = 0;
    for (int i = 1; i < n; i++) {
        bool flag = false;
        for (int u = 1; u <= n; u++)
            for (auto &e : g[u])
                if (dist[e.first] > dist[u] + e.second) {
                    dist[e.first] = dist[u] + e.second;
                    flag          = true;
                }
        if (!flag)
            break;
    }
    for (int u = 1; u <= n; u++)
        for (auto &e : g[u])
            if (dist[e.first] > dist[u] + e.second)
                return false;
    return true;
}

void output() {
    int minDist = dist[1];
    for (int i = 2; i <= n; i++)
        if (dist[i] < minDist)
            minDist = dist[i];
    for (int i = 1; i <= n; i++)
        printf("%d\n", dist[i] - minDist);
}

int main() {
    input();
    if (process())
        output();
    else
        printf("NO SOLUTION\n");
    return 0;
}
