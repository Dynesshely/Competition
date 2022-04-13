// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 4000;
// int N, M, a[maxn], b[maxn], t[maxn];
// int main(){
//     scanf("%d%d", &N, &M);
//     for(int i = 0; i < M; ++ i)
//         scanf("%d%d", &a[i], &b[i], &t[i]);
    
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 100010, M = 400010;

inline int read(){
    int res = 0; bool flag = 0; char c = getchar();
    while (c < '0' or c > '9'){ if (c == '-') flag = 1; c = getchar(); }
    while (c >= '0' and c <= '9'){ res = res * 10 + c - '0'; c = getchar(); }
    return flag ? -res : res;
}

int n, m, A[M], B[M], C[M], what[M], is[M], fafa[N], fa[N], ans[N];
bool itis[M];

inline int Find(int x){ return x == fa[x] ? x : fa[x] = Find(fa[x]); }

struct edge { int nxt, to, val; }ed[M];
struct date{ int x, y, w; }cf[M];

int head[N], cnt;

inline void add(int x, int y, int z, int gg) {
    cnt++; ed[cnt].nxt = head[x];
    ed[cnt].to = y; ed[cnt].val = z;
    head[x] = cnt; what[cnt] = gg;
}

inline void add(int x, int y){
    cnt++; ed[cnt].nxt = head[x];
    ed[cnt].to = y; head[x] = cnt;
}

bool cmp(date a, date b){ return a.w < b.w; }

void dfs(int x){
    for (register int i = head[x] ;i ; i = ed[i].nxt){
        int to = ed[i].to;
        if (to == fafa[x]) continue;
        fafa[to] = x; dfs(to);
    }
}

struct dij{int x, w;};

bool operator <(const dij &a,const dij &b){ return a.w > b.w; }

int dis[N]; bool vis[N];

inline void Dijkstra(int haha){
    memset(dis, 0x3f, sizeof dis);
    priority_queue <dij> q;
    dis[haha] = 0;
    q.push((dij){ haha, 0 });
    while (!q.empty()){
        dij t = q.top(); q.pop(); int x = t.x;
        if (vis[x]) continue; vis[x] = 1;
        for (register int i = head[x] ; i ; i = ed[i].nxt){
            int to = ed[i].to;
            if (!vis[to] and dis[to] > dis[x] + ed[i].val){
                is[to] = what[i];
                dis[to] = dis[x] + ed[i].val;
                q.push((dij){to, dis[to]});
            }
        }
    }
}

int main(){    
    n = read(), m = read();
    for (register int i = 1 ; i <= m ; i ++){
        A[i] = read(), B[i] = read(), C[i] = read();
        add(A[i], B[i], C[i], i);
        add(B[i], A[i], C[i], i);
    }
    Dijkstra(1); cnt = 0;
    memset(head, 0, sizeof head);
    for (register int i = 2 ; i <= n ; i ++){
        int x = is[i]; add(A[x], B[x]);
        add(B[x], A[x]); itis[x] = 1;
    }
    dfs(1); int num = 0;
    for (register int i = 1 ; i <= m ; i ++){
        if (itis[i]) continue;
        cf[++num] = (date) {A[i], B[i], dis[A[i]] + dis[B[i]] + C[i]};
    }
    sort (cf + 1, cf + 1 + num, cmp);
    for (register int i = 1 ; i <= n ; i ++) fa[i] = i, ans[i] = -1;
    for (register int i = 1 ; i <= num ; i ++){
        int x = cf[i].x, y = cf[i].y;
        x = Find(x), y = Find(y);
        while (x != y){
            if (dis[x] < dis[y]) swap(x, y);
            ans[x] = cf[i].w - dis[x];
            fa[x] = fafa[x];
            x = Find(x);
        }
    }
    for (register int i = 2 ; i <= n ; i ++)
        printf("%d\n", ans[i]);
    return 0;
}