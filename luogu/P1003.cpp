#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int n, x, y, a[MAXN], b[MAXN], g[MAXN], k[MAXN], ans = -1;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)
		scanf("%d %d %d %d", &a[i], &b[i], &g[i], &k[i]);
	scanf("%d %d", &x, &y);
	for(int i = 1; i <= n; ++ i)
		if(x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + k[i]) ans = i;
	printf("%d\n", ans);
	return 0;
}
