#include <bits/stdc++.h>
using namespace std;
int f[50], k;
int main(){
	f[1] = 1, f[2] = 1;
	for(int i = 3; i <= 50; ++ i) f[i] = f[i - 1] + f[i - 2];
	scanf("%d", &k);
	printf("%d\n", f[k]);
	return 0;
}