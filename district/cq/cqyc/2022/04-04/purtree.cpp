#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e6+10,p=998244353;
int head[N],to[N],nxt[N],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}int n,a[N],f[N][2],g[N][2],l[N],r[N],idx;
inline int inv(int a,int b=p-2){
	int x=1;while(b){
		if(b&1)(x*=a)%=p;
		(a*=a)%=p,b>>=1;
	}return x;
}
void dfs(int u,int fa){
	int son=0;g[u][0]=g[u][1]=1;
	l[u]=idx+1;
	go(u){
		int v=to[i];if(v==fa)continue;
		son++,dfs(v,u);
	}if(!son)return f[u][0]=a[u],f[u][1]=0,l[u]=r[u]=++idx,void();
	int mn=1e9,mul=1;
	go(u){
		int v=to[i];if(v==fa)continue;
		f[u][1]+=f[v][0];
		(mul*=g[v][0])%=p;
		if(mn>f[v][1]-f[v][0])mn=f[v][1]-f[v][0];
	}f[u][0]=f[u][1],f[u][1]+=mn;
	g[u][1]=0,g[u][0]=mul;
	if(mn+a[u]<0)f[u][0]+=mn+a[u];
	go(u){
		int v=to[i];if(v==fa)continue;
		if(f[v][1]-f[v][0]==mn){
			(g[u][1]+=mul*inv(g[v][0])%p*g[v][1])%=p;
		}
	}
	if(mn+a[u]<0)g[u][0]=g[u][1];
	if(mn+a[u]==0)(g[u][0]+=g[u][1])%=p;
	r[u]=idx;
}int ok[N];
struct node{
	int u,v,w,id;
	bool operator < (const node &x) const {
		return w<x.w;
	}
}e[N];int fa[N];
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
void merge(int x,int y){fa[get(x)]=get(y);}
int stk[30],tp;
void write(int x){
	do stk[++tp]=x%10,x/=10;while(x);
	while(tp)putchar(stk[tp--]^48);
}
signed main(){
	freopen("purtree.in","r",stdin);
	freopen("purtree.out","w",stdout);
	For(i,1,n=read())a[i]=read();
	For(i,2,n){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}dfs(1,0),cout<<f[1][0]<<endl;
	int k=read();
	For(i,1,n)e[i]=(node){l[i],r[i]+1,a[i],i};sort(e+1,e+1+n);
	For(i,1,idx+1)fa[i]=i;
	for(int i=1,j=1;i<=n;i=j){
		while(j<=n&&e[j].w==e[i].w)j++;
		For(k,i,j-1)if(get(e[k].u)!=get(e[k].v))ok[e[k].id]=1;
		For(k,i,j-1)merge(e[k].u,e[k].v);
	}
//	int res=0;For(i,1,n)if(ok[i])res++;cout<<res<<endl;
	if(k>=2)For(i,1,n)if(ok[i])write(i),putchar(' ');
	if(k>=3)cout<<endl<<g[1][0]<<endl;
	return 0;
}

