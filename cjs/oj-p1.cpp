#include <bits/stdc++.h>
using namespace std;
int n, m, s[100010];
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++ i) { int tmp; scanf("%d", &tmp); s[tmp] ++; }
	for(int i = 1; i <= n; ++ i)
		if(s[i] != 0)
			for(int j = 1; j <= s[i]; ++ j)
				printf("%d ", i);
	printf("\n");
	return 0;
}
