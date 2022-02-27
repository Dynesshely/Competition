#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define mp make_pair
const int N = 5e4 + 10, M = 52;
int n, k, b[N];
char s[M][M];
vector<PII> e[N * M];
int dist[N * M];
void Add(int x, int y, int w = 0, int f = 0) { e[x].push_back(mp(y, w)); if(f) e[y].push_back(mp(x, w)); }
#define get_l(x, t) ((x) + (t) * n) // 第t层点x的映射
void build() {
	// 1. 1至n层内部连边
	for(int i = 1; i <= k; i ++ )
		for(int j = 1; j <= n - 1; j ++ )
			Add(get_l(j, i), get_l(j + 1, i), 1, 1);
	// 2. 由第0层向其它层等效加边
	for(int i = 1; i <= n; i ++ ) Add(i, get_l(i, b[i]));
	// 3. 由其它层向第0层等效加边
	for(int i = 1; i <= k; i ++ )
		for(int j = 1; j <= n; j ++ )
			if(s[i][b[j]] == '1') Add(get_l(j, i), j);
}
void work() {
	#ifdef debug
	for(int i = 1; i <= get_l(n, k); i ++ ) {
		for_each(e[i].begin(), e[i].end(), [](PII x) -> void { cout << x.first << " "; });
		cout << endl;
	}
	#endif
	memset(dist, 0x3f, sizeof dist);
	deque<int> Q;
	Q.push_back(1); dist[1] = 0;
	while(!Q.empty()) {
		int t = Q.front(); Q.pop_front();
		for(unsigned i = 0; i < e[t].size(); i ++ ) {
			int u = e[t][i].first, w = e[t][i].second;
			if(dist[u] > dist[t] + w) {
				dist[u] = dist[t] + w;
				if(w) Q.push_back(u);
				else Q.push_front(u);
			}
		}
	}
	printf("%d\n", dist[n] > 1e9 ? -1 : dist[n]);
}
int main() {
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i ++ ) scanf("%d", b + i);
	for(int i = 1; i <= k; i ++ )
		scanf("%s", s[i] + 1); // 下标从1开始
	build();
	work();
	return 0;
}
