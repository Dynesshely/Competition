#include <bits/stdc++.h>
using namespace std;
const int NN = 300;
int m, n, w[NN], c[NN], f[NN][NN];
int main(){
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= n; ++ i){
		scanf("%d %d", &w[i], &c[i]);
	}
	for(int i = 1; i <= n; ++ i){
		for(int v = m; v > 0; -- v){
			if(w[i] <= v) f[i][v] = max(f[i - 1][v], f[i - 1][v - w[i]] + c[i]);
			else f[i][v] = f[i - 1][v];
		}
	}
	printf("%d\n", f[n][m]);
	return 0;
}
