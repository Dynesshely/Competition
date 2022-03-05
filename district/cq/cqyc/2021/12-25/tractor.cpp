#include <bits/stdc++.h>
using namespace std;
int N, mmap[600][600], tot, ans = 0x3fffffff;
bool via[600][600];
int p(int n){ return n * n; }
void init_tot(){ tot = p(N) % 2 == 0 ? p(N) / 2 : (p(N) * 1.0 / 2.0 - p(N) / 2 >= 0.5 ? p(N) / 2 + 1 : p(N) / 2); }
void dfs(int si, int sj, int li, int lj, int sum, int pd){
	if(pd == tot){ ans = min(ans, sum); return; }
	else if(mmap[si][sj] - mmap[li][lj] < 0) return;
	else{
		via[si][sj] = 1;
		if(ans < sum) return;
		else{
			if(si - 1 > 0 && si - 1 <= N && !via[si - 1][sj])
				dfs(si - 1, sj, si, sj, sum + mmap[si][sj] - mmap[li][lj], pd + 1);
			if(si + 1 > 0 && si + 1 <= N && !via[si + 1][sj])
				dfs(si + 1, sj, si, sj, sum + mmap[si][sj] - mmap[li][lj], pd + 1);
			if(sj - 1 > 0 && sj - 1 <= N && !via[si][sj - 1])
				dfs(si, sj - 1, si, sj, sum + mmap[si][sj] - mmap[li][lj], pd + 1);
			if(sj + 1 > 0 && sj + 1 <= N && !via[si][sj + 1])
				dfs(si, sj + 1, si, sj, sum + mmap[si][sj] - mmap[li][lj], pd + 1);
		}
	}
}
int main(){
	// freopen("tractor.in", "r", stdin);
	// freopen("tractor.out", "w", stdout);
	scanf("%d", &N);
	init_tot();
	for(int i = 1; i <= N; ++ i)
		for(int j = 1; j <= N; ++ j)
			scanf("%d", &mmap[i][j]);
	for(int i = 1; i <= N; ++ i)
		for(int j = 1; j <= N; ++ j){
			memset(via, 0, sizeof(via));
			dfs(i, j, i, j, 0, 0);
		}
	printf("%d\n", ans);
	return 0;
}

