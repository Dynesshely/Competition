#include <bits/stdc++.h>
using namespace std;
const int maxn = 10001, maxe = 100001;
int n, m, tot, ver[maxe], val[maxe], ne[maxe], head[maxn], dist[maxn], white[maxn];
void add(int u, int v, int w) { tot ++; ver[tot] = v; val[tot] = w; ne[tot] = head[u]; head[u] = tot; }
struct Node { int v, d; };
bool operator < (Node x, Node y) { return x.d > y.d; }
priority_queue<Node> q;
void dijkstra(int s){
	memset(dist, 0x3f, sizeof(int)*(n+1));
	dist[s] = 0; q.push({s, dist[s]});
	while(q.size() > 0){
		int u = q.top().v; q.pop();
		while(white[u] && q.size() > 0){ u = q.top().v; q.pop(); }
		if(white[u]) break;
		white[u] = 1; int p = head[u];
		while(p){
			int v = ver[p], w = val[p];
			if(!white[v] && dist[u] + w < dist[v]){ dist[v] = dist[u] + w; q.push({v, dist[v]}); }
			p = ne[p];
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	int u, v, w;
	while(m--){ scanf("%d%d%d", &u, &v, &w); if(u != v) { add(u, v, w); add(v, u , w); } }
	dijkstra(1);
	printf("%d\n", dist[n]);
	return 0;
}