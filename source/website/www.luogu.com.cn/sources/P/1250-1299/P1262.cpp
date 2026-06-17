#include <bits/stdc++.h>
using namespace std;

const int INF  = 0x3f3f3f3f;
const int MAXN = 3005;

int         n, p, r;
int         cost[MAXN];
vector<int> graph[MAXN];

int         dfn[MAXN], low[MAXN], sccId[MAXN], sccCnt, timer;
int         stk[MAXN], top;
bool        inStk[MAXN];
int         minCost[MAXN];
vector<int> dag[MAXN];
int         indeg[MAXN];
bool        reachable[MAXN];
bool        dagEdge[MAXN][MAXN];

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    stk[top++]      = u;
    inStk[u]        = true;
    for (int v : graph[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStk[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        int v;
        do {
            v        = stk[--top];
            inStk[v] = false;
            sccId[v] = sccCnt;
        } while (v != u);
        ++sccCnt;
    }
}

void input() {
    scanf("%d", &n);
    scanf("%d", &p);
    memset(cost, 0x3f, sizeof(cost));
    for (int i = 0; i < p; ++i) {
        int id, c;
        scanf("%d%d", &id, &c);
        cost[id] = c;
    }
    scanf("%d", &r);
    for (int i = 0; i < r; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
    }
}

void process() {
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i);

    for (int i = 0; i < sccCnt; ++i)
        minCost[i] = INF;
    for (int i = 1; i <= n; ++i)
        if (cost[i] < minCost[sccId[i]])
            minCost[sccId[i]] = cost[i];

    for (int u = 1; u <= n; ++u) {
        int su = sccId[u];
        for (int v : graph[u]) {
            int sv = sccId[v];
            if (su != sv && !dagEdge[su][sv]) {
                dagEdge[su][sv] = true;
                dag[su].push_back(sv);
                ++indeg[sv];
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < sccCnt; ++i)
        if (minCost[i] != INF) {
            reachable[i] = true;
            q.push(i);
        }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : dag[u])
            if (!reachable[v]) {
                reachable[v] = true;
                q.push(v);
            }
    }
}

void output() {
    int minUnreachable = INF;
    for (int i = 1; i <= n; ++i)
        if (!reachable[sccId[i]])
            minUnreachable = min(minUnreachable, i);

    if (minUnreachable == INF) {
        int tot = 0;
        for (int i = 0; i < sccCnt; ++i)
            if (indeg[i] == 0)
                tot += minCost[i];
        printf("YES\n%d\n", tot);
    } else
        printf("NO\n%d\n", minUnreachable);
}

int main() {
    input();
    process();
    output();
    return 0;
}
