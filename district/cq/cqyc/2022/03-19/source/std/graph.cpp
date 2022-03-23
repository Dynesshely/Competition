#include<cstdio>
#define R register
#define IL inline
#define mod 1000000007
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
int n,m,u,v,ans;
int lx[300050],rx[300050],s[300050];
long long solve(R int l,R int r){
	if(l==r){
		if(lx[l]==l&&rx[l]==l)return 1;
		return 0;
	}
	R int mid=l+r>>1,ml,mr,nr;
	R long long res=(solve(l,mid)+solve(mid+1,r))%mod;
	mr=mid+1,s[mid]=0;
	for(R int i=mid+1;i<=r;++i){
		if(rx[i]>mr)mr=rx[i];
		s[i]=s[i-1]+(mr==i);
	}
	ml=mid,mr=mid+1,nr=mid+1;
	for(R int i=mid;i>=l;--i){
		if(ml>lx[i])ml=lx[i];
		if(mr<rx[i])mr=rx[i];
		while(nr<=r&&lx[nr]>=i)++nr;
		if(i==ml&&nr>mr)res=(res+s[nr-1]-s[mr-1])%mod;
	}
	return res;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(R int i=1;i<=n;++i)lx[i]=rx[i]=i;
	for(R int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		lx[u]=Min(lx[u],v),rx[u]=Max(rx[u],v);
	}
	printf("%lld",solve(1,n));
	return 0;
}
