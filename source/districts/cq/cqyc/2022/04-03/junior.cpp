#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e5+10;
int n,m;
struct node{
	int u,v,w;
	bool operator < (const node &x) const {
		return w<x.w;
	}
}e[N];int cnt;
int fa[N],ok[N],ans;
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
bool merge(int x,int y){
	x=get(x),y=get(y);
	if(ok[x]&&ok[y])return 0;
	if(x==y)return ok[x]=1;
	fa[x]=y,ok[y]|=ok[x];
	return 1;
}
signed main(){
    freopen("junior.in","r",stdin);
    freopen("junior.out","w",stdout);
	n=read(),m=read();For(i,1,n+m)fa[i]=i;
	For(i,1,n)For(j,1,m)e[++cnt]=(node){i,j+n,read()};
	sort(e+1,e+1+cnt);For(i,1,cnt){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(merge(u,v))ans+=w;
	}cout<<ans<<endl;
	return 0;
}