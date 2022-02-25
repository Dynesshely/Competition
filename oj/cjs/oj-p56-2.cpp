#include<bits/stdc++.h>
using namespace std;
const int maxn = 100001, maxe = 1000001, mod=0x7fffffff;
int head[maxn],ver[maxe],val[maxe],ne[maxe],tot,n,m,dist[maxn],white[maxn];
struct Node{ int v, d;};
bool operator < (Node x, Node y){ return x.d > y.d;}
priority_queue<Node> q;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=0;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    if(f) return x;
    return ~(x-1);
}
void add(int u,int v, int w){ tot++;ver[tot]=v;val[tot]=w; ne[tot]=head[u];head[u]=tot; }
void dijkstra();
int main(){
	n=read();m=read();
	int u,v,w;
	while(m--){ u=read();v=read();w=read(); if(u==v) continue; add(u,v,w); add(v,u,w);}
	dijkstra(); cout<<dist[n]<<endl;
	return 0;
}
void dijkstra(){
	memset(dist,0x3f,sizeof(int)*(n+1));dist[1]=0; q.push({1,dist[1]});
	while(q.size()>0){
		int u = q.top().v; q.pop(); 
		while(white[u] && q.size()>0){ u = q.top().v; q.pop(); }
		if(white[u]) break;
		white[u]=1;int p = head[u];
		while(p){
			int v = ver[p], w = val[p];
			if(!white[v] && dist[u] + w < dist[v]) { dist[v]=dist[u]+w; q.push({v,dist[v]});}
			p = ne[p];
		}
	}
}
