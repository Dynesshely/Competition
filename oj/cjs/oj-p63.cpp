#include <bits/stdc++.h>
using namespace std;
int a[100005], n, i, ans = 0;
int main(){
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		if(a[i] > a[i-1]) ans += a[i] - a[i - 1];
	}
	printf("%d\n", ans);
}