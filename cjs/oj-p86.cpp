#include <bits/stdc++.h>
using namespace std;
int n, cps[110][110], i, j, tot = 0, k = 0, w_num = 0;
struct ws{ // way struct
	int x, y, v; // x - point , y - point , v - value
}w[10010]; // ways array
void data_in(){ // data input function
	scanf("%d", &n); // scan n
	for(i = 1; i <= n; ++ i) for(j = 1; j <= n; ++ j) scanf("%d", &cps[i][j]);
}
bool cmp(ws a, ws b){ return a.v > b.v; }
void data_init(){ // data init
	for(i = 2; i <= n; ++ i)
		for(j = 1; j <= n; ++ j){
			if(cps[i][j] != cps[j][i]) w[w_num].x = i, w[w_num].y = j, w[w_num ++].v = cps[i][j];
		}
}
void kruskal(){ // kruskal
	sort(w + 1, w + )
}
int main(){ // main
	data_in(); data_init(); // input data and init data
	int f[n + 1]; // fathers array
	for(int i = 1; i <= n; ++ i) f[i] = i; // init fathers array
	
	return 0;
}