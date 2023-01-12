# include <cstdio>
# define N 1000010
int a[N],pr[N/10],pr_n=0,mn[N],t_n,t[10],mul[200],lg[200],sm[10];
long long f[N][2];
bool p[N];
long long max(long long x,long long y) {return x>y?x:y;}
int main() {
	freopen("war.in","r",stdin);
	freopen("war.out","w",stdout);
	int n,i,j,ii,tot,lb;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=2;i<=n;i++) {
		if(!p[i]) pr[++pr_n]=i, mn[i]=i;
		for(j=1;j<=pr_n && i*pr[j]<=n;j++) {
			p[i*pr[j]]=true;
			mn[i*pr[j]]=pr[j];
			if(!(i%pr[j])) break;
		}
	}
	for(i=0;i<=7;i++) lg[1<<i]=i;
	for(i=2;i<=n;i++) {
		ii=i; t_n=-1;
		while(ii>1) {
			if(t_n<0 || t[t_n]!=mn[ii]) t[++t_n]=mn[ii], sm[t_n]=1;
			sm[t_n]*=mn[ii];
			ii/=mn[ii];
		}
		tot=(1<<t_n+1)-1; mul[0]=1;
		for(j=1;j<=tot;j++) {
			lb=j&(-j);
			mul[j]=mul[j^lb]*sm[lg[lb]];
		}
		for(j=1;j<tot;j++) {
			f[i][0]=max(f[i][0],max(max(f[mul[j]][0]+f[mul[tot^j]][0],f[mul[j]][0]+f[mul[tot^j]][1]),max(f[mul[j]][1]+f[mul[tot^j]][0],f[mul[j]][1]+f[mul[tot^j]][1])));
			f[i][1]=max(f[i][1],f[mul[j]][0]+f[mul[tot^j]][0]);
		}
		f[i][1]+=a[i];
		if(p[i]) ans=max(ans,max(f[i][0],f[i][1])+max(a[1],0));
		else ans=max(max(ans,a[1]),max(f[i][0],f[i][1]));
		for(j=i+i;j<=n;j+=i) {
			f[j][0]=max(f[j][0],max(f[i][0],f[i][1]));
			f[j][1]=max(f[j][1],f[i][0]);
		}
	}
	printf("%lld",ans);
	return 0;
}
