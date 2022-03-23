#include<cstdio>
char ch,B[1<<15],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?0:*S++)
int aa;int F(){
	while(ch=getc(),ch<'0'||ch>'9');aa=ch-'0';
	while(ch=getc(),ch>='0'&&ch<='9')aa=aa*10+ch-'0';return aa;
}
int n,i,x[100010],y[100010],a[100010],b[100010];long long ans;main(){
	freopen("feet.in","r",stdin);
	freopen("feet.out","w",stdout);
	for(n=F(),i=1;i<=n;i++)a[x[i]=F()]++,b[y[i]=F()]++;
	for(i=1;i<=n;i++)ans+=1LL*(a[x[i]]-1)*(b[y[i]]-1);
	printf("%lld",ans);
}
