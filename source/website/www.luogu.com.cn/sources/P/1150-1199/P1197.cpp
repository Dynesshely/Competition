#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400010;
const int MAXM = 200010;

int  n, m, k;
int  head[MAXN], nxt[MAXM * 2], to[MAXM * 2], tot;
int  fa[MAXN], sz[MAXN];
bool broken[MAXN];
int  attack[MAXN];
int  ans[MAXN];

void addEdge(int u, int v) {
    nxt[++tot] = head[u];
    to[tot]    = v;
    head[u]    = tot;
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
        return false;
    if (sz[x] < sz[y])
        swap(x, y);
    fa[y] = x;
    sz[x] += sz[y];
    return true;
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &attack[i]);
        broken[attack[i]] = true;
    }
}

void process() {
    for (int i = 0; i < n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    int comp = 0;
    for (int i = 0; i < n; i++) {
        if (broken[i])
            continue;
        comp++;
        for (int e = head[i]; e; e = nxt[e]) {
            int v = to[e];
            if (!broken[v] && unite(i, v))
                comp--;
        }
    }
    ans[k + 1] = comp;
    for (int i = k; i >= 1; i--) {
        int u     = attack[i];
        broken[u] = false;
        comp++;
        for (int e = head[u]; e; e = nxt[e]) {
            int v = to[e];
            if (!broken[v] && unite(u, v))
                comp--;
        }
        ans[i] = comp;
    }
}

void output() {
    printf("%d\n", ans[1]);
    for (int i = 2; i <= k + 1; i++)
        printf("%d\n", ans[i]);
}

int main() {
    input();
    process();
    output();
    return 0;
}
