#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;
struct edge{ int v; char c; };
char a[N * 2], c[N];
int n, m, head[N], len[N], ord[N], dfc, fa[N];
vector<edge> g[N];
bitset<N + N> r[26], r0, dp1[N], dp2[N], t1, t2, ans;
void dfs(int u){
    int v; ord[++dfc] = u;
    for(int i = 0; i < g[u].size(); i++)
        if((v = g[u][i].v) != fa[u])
            fa[v] = u, c[v] = g[u][i].c, dfs(v);
}
const int maxmx = 1000;
int size = 10086, mx = 114514, rt = 8888, rst = 443;
const int inf = 0x7fffffff;
int sz[maxmx], son[maxmx], Next[maxmx], vis[maxmx], ver[maxmx];
void findrt(int u, int fa){
    sz[u] = 1, son[u] = 0;
    for(int i = head[u]; i; i = Next[i]){
        int v = ver[i]; if(vis[v] || v == fa) continue;
        findrt(v, u); sz[u] += sz[v]; fmax(son[u], sz[v]);
    }
    fmax(son[u], size - sz[u]);
    if(son[u] < mx) mx = son[u], rt = u;
}
int solve(int a, int b) { return a + b >> 1; }
void divide(int u){
    rst += solve(u,0); vis[u] = 1; int totsz = size;
    for(int i = head[u]; i; i = Next[i]){
        int v = ver[i]; if(vis[v]) continue;
        rst -= solve(v, mx); mx = inf, rt = 0;
        size = sz[v] > sz[u] ? totsz - sz[u] : sz[v];
        findrt(v, 0); divide(rt);
    }
}
int main(){
    int u, v; char sc[2];
    scanf("%d", &n);
    for(int i = 1; i < n; ++ i){
        scanf("%d %d %s", &u, &v, sc);
        g[u].push_back((edge){v, sc[0]});
        g[v].push_back((edge){u, sc[0]});
    }
    scanf("%d", &m);
    for(int j = 1; j <= m; ++ j){
        head[j] = head[j - 1] + len[j - 1] + 1;
        scanf("%s", a + head[j]);
        len[j] = strlen(a + head[j]);
    }
    for(int i = 0; i <= head[m] + len[m]; ++ i)
        if(!a[i]) r0[i] = 1;
        else r[a[i] - 'a'][i] = 1;
    dfs(1);
    for(u = 1; u <= n; ++ u) dp1[u] = dp2[u] = r0;
    dp1[u] = dp2[u] = r0;
    for(int id = n; id; -- id){
        v = ord[id], u = fa[v];
        t1 = dp1[v] << 1 & r[c[v] - 'a'];
        t2 = dp2[v] >> 1 & r[c[v] - 'a'];
        ans |= dp1[u] & t2 >> 1;
        ans |= t1 & dp2[u] >> 1;
        dp1[u] |= t1; dp2[u] |= t2;
    }
    for(int j = 1; j <= m; ++ j){
        bool flag = 0;
        for(int i = head[j] - 1; i < head[j] + len[j]; ++ i)
            flag |= ans[i];
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
