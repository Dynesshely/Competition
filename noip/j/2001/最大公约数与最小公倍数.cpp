#include<bits/stdc++.h>
using namespace std;
int n,m,f[1000001],v[1000001],sum,x,y,ans;
inline int gy(int x,int y){
	for(int i=min(x,y);i>=2;i--){
		if(x%i==0&&y%i==0){
			if(i==n) return 0;
			break;
		}
	}
	return 1;
}
int main(){
	scanf("%d %d",&n,&m);
	for(;;){
		sum++;
		f[sum]=n*sum;
		if(f[sum]>m){
			sum--;
			break;
		}
	}
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=sum;j++){
			if(n*(f[i]/n)*(f[j]/n)==m&&!gy(f[i],f[j])){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
