#include <bits/stdc++.h>
using namespace std;

int              n, m;
map<string, int> id;
vector<int>      g[8005];
int              wife[4005], husband[4005];
int              dfn[8005], low[8005], scc[8005], stk[8005], top, idx, sccCnt;
bool             inStk[8005];

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    stk[++top]      = u;
    inStk[u]        = true;
    for (int v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++sccCnt;
        int v;
        do {
            v        = stk[top--];
            inStk[v] = false;
            scc[v]   = sccCnt;
        } while (v != u);
    }
}

void input() {
    scanf("%d", &n);
    char girl[16], boy[16];
    for (int i = 1; i <= n; ++i) {
        scanf("%s%s", girl, boy);
        if (!id.count(girl))
            id[girl] = id.size();
        if (!id.count(boy))
            id[boy] = id.size();
        wife[i]    = id[girl];
        husband[i] = id[boy];
        g[wife[i]].push_back(husband[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%s%s", girl, boy);
        int u = id[girl], v = id[boy];
        g[v].push_back(u);
    }
}

void process() {
    int tot = id.size();
    for (int i = 0; i < tot; ++i)
        if (!dfn[i])
            tarjan(i);
}

void output() {
    for (int i = 1; i <= n; ++i) {
        if (scc[wife[i]] == scc[husband[i]])
            printf("Unsafe\n");
        else
            printf("Safe\n");
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}
