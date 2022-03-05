#include<bits/stdc++.h>
using namespace std;
int dp[1 << 19] , sum[1 << 19];
int n , k , a[20];
signed main(){
	memset(dp , 0x3f , sizeof(dp));
	dp[0] = 0;
	scanf("%d%d",&n , &k);
	for(int i = 1 ; i <= n ; i ++) scanf("%d",&a[i]);
	for(int i = 1 ; i < (1 << n) ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			if(1 << (j - 1) & i) sum[i] += a[j];
	for(int i = 1 ; i < (1 << n) ; i ++)
		for(int j = i ; j ; j = (j - 1) & i){
			if(sum[j] > k) continue ;
			dp[i] = min(dp[i] , dp[i - j] + 1);
		}
    printf("%d\n",dp[(1 << n) - 1]);
	return 0;
}
