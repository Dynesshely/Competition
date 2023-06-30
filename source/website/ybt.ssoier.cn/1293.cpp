#include <bits/stdc++.h>
using namespace std;
int v, m;
long long c[10000], f[10000];
int main() {
	scanf("%d", &v);
	c[1] = 10, c[2] = 20, c[3] = 50, c[4] = 100;
	f[0] = 1;
	if(v == 0){
		printf("0\n");
		return 0;
	}
	for(int i = 1; i <= 4; i ++)
		for(int j = c[i]; j <= v; j ++)
			f[j] += f[j - c[i]];
	printf("%lld\n", f[v]);
	return 0;
}