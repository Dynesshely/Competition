#include<cstdio>
int a[10],cnt[1024];long long ans;char B[1<<26];
main(){
		freopen("pals.in","r",stdin);
		freopen("pals.out","w",stdout);
	register int n;
	scanf("%d",&n),ans=1ll*n*(n-1)/2,fread(B,1,1<<26,stdin);
	for(register char *S=B;n--;){
		register int x=0;
		for(;*S<'0';S++);
		for(;a[*S++-'0']=1,*S>='0';);
		for(register int i=0;i<10;i++)x+=a[i]<<i,a[i]=0;
		cnt[x]++;
	}
	for(register int i=0;i<1024;i++)
	for(register int j=i+1;j<1024;j++)
	if((i&j)==0)ans-=1LL*cnt[i]*cnt[j];
	printf("%lld",ans);
}
