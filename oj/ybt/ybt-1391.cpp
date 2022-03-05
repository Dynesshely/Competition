#include <bits/stdc++.h>
using namespace std;
int n, k, i, w_num = 1, f[110], tot = 0;
struct wwws{
	int x, y, v;
}w[1010];
bool cmp(wwws a, wwws b) { return a.v < b.v; }
int find(int x){
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}
void combine(int a, int b){ f[a] = b; }
int main(){
	scanf("%d %d", &n, &k);
	for(i = 1; i <= k; ++ i){
		scanf("%d %d %d", &w[w_num].x, &w[w_num].y, &w[w_num].v);
		w_num ++;
	}
	-- w_num;
	sort(w + 1, w + w_num + 1, cmp);
	for(int i = 1; i <= w_num; ++ i)
		if(find(w[i].x) != find(w[i].y)){
			combine(w[i].x, w[i].y);
			tot += w[i].v; ++ k;
			if(k == w_num + 1) break;
		}
	printf("%d\n", tot);
	return 0;
}