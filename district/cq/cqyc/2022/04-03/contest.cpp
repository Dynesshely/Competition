#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define pb push_back
#define int long long
char buf[(1<<21)+5],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=5e5+10,inf=2e18;
int n,q,a[N],b[N];
struct Tree{
	#define ls (k<<1)
	#define rs (k<<1|1)
	struct node{//l<=[x]<=r:val=[x]+b
		int l,r,b;
		node(){l=r=b=0;}
		node(int L,int R,int B){l=L,r=R,b=B;}
		bool operator & (const node &x) const {return max(l+b,x.l)<=min(r+b,x.r);}
		node operator * (const node &x) const {return node(max(l,x.l-b),min(r,x.r-b),b+x.b);}
		bool operator < (const node &x) const {return r<x.r;}
	};vector<node> t[N<<2];
	void build(int k,int l,int r){
		if(l==r)return t[k].pb(node(0,a[l],0)),t[k].pb(node(a[l]+1,inf,b[l])),void();
		int m=l+r>>1;build(ls,l,m),build(rs,m+1,r);
		for(int i=0,j=0;i<t[ls].size();i++){
			while(j<t[rs].size()&&!(t[ls][i]&t[rs][j]))j++;
			int p=j;while(p<t[rs].size()&&(t[ls][i]&t[rs][p]))t[k].pb(t[ls][i]*t[rs][p]),p++;
		}
	}int now;
	void work(int k,int l,int r,int x,int y){
		if(x<=l&&r<=y)return now+=lower_bound(t[k].begin(),t[k].end(),node(0,now,0))->b,void();
		int m=l+r>>1;
		if(x<=m)work(ls,l,m,x,y);
		if(y>m)work(rs,m+1,r,x,y);
	}
	int get(int l,int r,int x){now=x,work(1,1,n,l,r);return now;}
}T;
signed main(){
    freopen("contest.in","r",stdin);
    freopen("contest.out","w",stdout);
	n=read(),q=read();int t=read(),lans=0;For(i,1,n)a[i]=read();For(i,1,n)b[i]=read();
	T.build(1,1,n);while(q--){
		int l=read(),r=read(),x=read();
		l^=(t*lans),r^=(t*lans),x^=(t*lans);
		if(x<0)printf("%lld\n",lans=x);
		else printf("%lld\n",lans=T.get(l,r,x));
	}
	return 0;
} 
