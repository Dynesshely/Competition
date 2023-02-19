# include <cstdio>
# include <algorithm>
# define N 100010
int n,pre[N],suf[N],mnsuf[N],mnpre[N],mxpre[N],mxsuf[N];
struct point{
	int x,y;
}a[N];
bool cmp(const point &i,const point &j) {return i.x<j.x;}
int abs(int x) {return x>=0?x:-x;}
int max(int x,int y) {return x>y?x:y;}
long long max(long long x,long long y) {return x>y?x:y;}
long long min(long long x,long long y) {return x<y?x:y;}
long long sq(int x) {return 1ll*x*x;}
long long gety(int l,int r) {return max(sq(a[r].x)+sq(max(pre[l-1],suf[r+1])),sq(max(mxpre[l-1],mxsuf[r+1])-min(mnpre[l-1],mnsuf[r+1])));}
long long getx(int l,int r) {return sq(a[r].x-a[l].x);}
long long solve() {
	int i,j,l,r,mid;
	long long ans;
	std::sort(a+1,a+n+1,cmp);
	pre[0]=suf[n+1]=0; mxpre[0]=mxsuf[n+1]=-1e9; mnpre[0]=mnsuf[n+1]=1e9;
	for(i=1;i<=n;i++) pre[i]=max(pre[i-1],abs(a[i].y)), mxpre[i]=max(mxpre[i-1],a[i].y), mnpre[i]=min(mnpre[i-1],a[i].y);
	for(i=n;i>=1;i--) suf[i]=max(suf[i+1],abs(a[i].y)), mxsuf[i]=max(mxsuf[i+1],a[i].y), mnsuf[i]=min(mnsuf[i+1],a[i].y);
	ans=min(sq(mxpre[n]-mnpre[n]),sq(a[n].x-a[1].x));;
	for(i=n,j=1;i>=1;i--) {
		while(j<n && a[j].x<-a[i].x) j++;
		if(j>i) break;
		l=j; r=i;
		while(l<r) {
			mid=l+r>>1;
			if(gety(mid,i)>getx(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=min(ans,max(getx(l,i),gety(l,i)));
		if(l>j) ans=min(ans,max(getx(l-1,i),gety(l-1,i)));
	}
	return ans;
}
int main() {
	freopen("len.in","r",stdin);
	freopen("len.out","w",stdout);
	int i;
	long long ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	ans=9e18;
	ans=solve();
	for(i=1;i<=n;i++) a[i].x*=-1;
	printf("%lld\n",min(ans,solve()));
	return 0;
}

