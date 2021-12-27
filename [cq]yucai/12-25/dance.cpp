#include <bits/stdc++.h>
using namespace std;
int N, M, pool[40][40], sln = 0, mls = 0x3fffffff;
bool via[40][40], add[40][40];
struct p{ int i, j; }ps[10];
void cad(int si, int sj, int ls);
void dfs(int si, int sj, int ls){
	if(via[si][sj]) return;
	else{
		via[si][sj] = 1; add[si][sj] = 1;
		if(si == ps[2].i && sj == ps[2].j){
			mls = min(mls, ls - 1);
			++ sln;
			via[si][sj] = 0;
			
//			printf("\n");
//			for(int i = 1; i <= N; ++ i){
//				for(int j = 1; j <= M; ++ j)
//					printf("%d ", via[i][j]);
//				printf("\n");
//			}
//			printf("\n");
			
			return;
		}
		cad(si - 1, sj - 2, ls);
		cad(si - 1, sj + 2, ls);
		cad(si + 1, sj - 2, ls);
		cad(si + 1, sj + 2, ls);
		cad(si - 2, sj - 1, ls);
		cad(si - 2, sj + 1, ls);
		cad(si + 2, sj - 1, ls);
		cad(si + 2, sj + 1, ls);
	}
}
void cad(int si, int sj, int ls){
	if(si > 0 && si <= N && sj > 0 && sj <= M && pool[si][sj] != 2)
		dfs(si, sj, pool[si][sj] == 1 ? ls : ls + 1);
}
int main(){
	freopen("dance.in", "r", stdin);
	freopen("dance.out", "w", stdout);
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; ++ i)
		for(int j = 1; j <= M; ++ j){
			scanf("%d", &pool[i][j]);
			if(pool[i][j] == 3) ps[1].i = i, ps[1].j = j;
			if(pool[i][j] == 4) ps[2].i = i, ps[2].j = j;
		}
	dfs(ps[1].i, ps[1].j, 0);
	if(sln == 0) printf("-1\n");
	else printf("%d\n%d\n", mls, sln);
	return 0;
}

