#include <bits/stdc++.h>
using namespace std;
const int maxn = 30005, maxm = 50005;
struct Edges{
    int next, to, weight;
}e[maxm << 4];
int dist[maxn], head[maxn], tot, n, m;
bool vis[maxn];
queue<int> q;
void link(int u, int v, int w){
    e[++tot] = (Edges){head[u], v, w};
    head[u] = tot;
}
void spfa(int s){
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    q.push(s); vis[s] = true;
    while(!q.empty()){
        int u = q.front(); q.pop(); vis[u] = false;
        for(int i = head[u]; i != -1; i = e[i].next){
            int v = e[i].to;
            if(dist[u] + e[i].weight > dist[v]){
                dist[v] = dist[u] + e[i].weight;
                if(!vis[v]){
                    q.push(v); vis[v] = true;
                }
            }
        }
    }
}
int main(){
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    while(m--){
        int l, r, c; scanf("%d%d%d", &l, &r, &c);
        link(l - 1, r, c);
    }
    for(int i = 1; i <= n; i++){
        link(i - 1, i, 0); link(i, i - 1, -1);
    }
    spfa(0);
    printf("%d\n", dist[n]);
    return 0;
}