#include <bits/stdc++.h>
#define MAXQ 1000010
using namespace std;
int N, M, f[20010], i, a[MAXQ], b[MAXQ], Q, c[MAXQ], d[MAXQ];
int find(int x){
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}
void combine(int a, int b) { f[find(b)] = find(a); }
int main(){
	scanf("%d %d", &N, &M);
	for(i = 1; i <= N; ++ i) f[i] = i;
	for(i = 1; i <= M; ++ i) scanf("%d %d", &a[i], &b[i]);
	scanf("%d", &Q);
	for(i = 1; i <= Q; ++ i) scanf("%d %d", &c[i], &d[i]);
	for(i = 1; i <= M; ++ i)
		if(find(a[i]) != find(b[i]))
			combine(a[i], b[i]);
	for(i = 1; i <= Q; ++ i)
		if(find(c[i]) == find(d[i])) printf("Yes\n");
		else printf("No\n");
	return 0;
}