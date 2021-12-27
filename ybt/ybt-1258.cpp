#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
int main(){
	scanf("%d", &n);
	int tower[n + 1][n + 1] = {}, f[n + 1][n + 1] = {};
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= i; ++ j){
			scanf("%d", &tower[i][j]);
			if(i == 1) f[1][1] = tower[1][1];
			if(i >= 2){
				f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + tower[i][j];
			}
		}
	}
	for(int i = 1; i <= n; ++ i){
		ans = max(ans, f[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}
