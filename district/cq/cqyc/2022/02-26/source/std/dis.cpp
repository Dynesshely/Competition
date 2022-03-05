#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int n,m;
const int N=1e6+10,INF=1e9;
int a[N],b[N],stk[N],tp,lst[N];
struct SegmentTree{
	#define ls (k<<1)
	#define rs (k<<1|1)
	int t[N<<2];
	void up(int k){t[k]=min(t[ls],t[rs]);}
	void build(int k,int l,int r){
		t[k]=INF;
		if(l==r)return t[k]=b[l],void();
		int m=l+r>>1;
		build(ls,l,m),build(rs,m+1,r);
		return up(k);
	}
	void mdf(int k,int l,int r,int pos,int val){
		if(l==r)return t[k]=val,void();
		int m=l+r>>1;
		(pos<=m)?(mdf(ls,l,m,pos,val)):(mdf(rs,m+1,r,pos,val)); 
		return up(k);
	}
	int query(int k,int l,int r,int x,int y){
		if(x<=l&&r<=y)return t[k];
		int m=l+r>>1;
		return min((x<=m)?query(ls,l,m,x,y):INF,(y>m)?query(rs,m+1,r,x,y):INF);
	}
}T;
int ans[N];
struct query{
	int l,r,id;
	bool operator < (const query &x) const {
		return r>x.r;
	}
}q[N];
bool cmp(int u,int v){
	return u+b[u]>v+b[v];
}
int STK[30],TP;
void write(int x){
	do STK[++TP]=x%10,x/=10;while(x);
	while(TP)putchar(STK[TP--]^48);
}
int c[N];
signed main(){
	freopen("dis.in","r",stdin);
	freopen("dis.out","w",stdout); 
	n=read(),m=read();
	For(i,1,n)a[i]=read(),stk[++tp]=a[i];
	memset(b,0x3f,sizeof b);
	sort(stk+1,stk+1+n),tp=unique(stk+1,stk+1+n)-stk;
	Rof(i,n,1){
		a[i]=lower_bound(stk+1,stk+1+tp,a[i])-stk;
		if(lst[a[i]])b[i]=min(b[i],lst[a[i]]-i);
		lst[a[i]]=i,c[i]=i;
	}
	T.build(1,1,n);
	sort(c+1,c+1+n,cmp);
	//[i,b[i]]
	For(i,1,m)q[i]=(query){read(),read(),i};
	sort(q+1,q+1+m);
	int now=1;
	For(i,1,m){
		int r=q[i].r,l=q[i].l,id=q[i].id;
		while(now<=n&&c[now]+b[c[now]]>r)T.mdf(1,1,n,c[now],INF),now++;
		ans[id]=T.query(1,1,n,l,r);
		if(ans[id]>r-l)ans[id]=-1;
	} 
	For(i,1,m)if(ans[i]>=1)write(ans[i]),putchar('\n');else puts("-1");
	return 0;
}
