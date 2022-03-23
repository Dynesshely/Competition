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
const int N=1e5+10,M=5e6+10;
struct node{
	int u,v,w;
	bool operator < (const node &x) const {
		return w<x.w;
	}
}e[M];int m;
int n;
struct point{
	int x,y;
}p[N];
#define E(x) ((x)*(x))
#define d(i,j) (E(p[i].x-p[j].x)+E(p[i].y-p[j].y))
#define pi pair<int,int>
#define fi first
#define se second
set<pi> s[50];
int fa[N];int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
bool merge(int x,int y){x=get(x),y=get(y);if(x==y)return 0;fa[x]=y;return 1;}
signed main(){
	freopen("ant.in","r",stdin);
	freopen("ant.out","w",stdout); 
	For(i,1,n=read())p[i].x=read(),p[i].y=read(),s[p[i].y].insert(pi(p[i].x,i));
	For(i,1,n)For(y,0,10){
		auto it=s[y].upper_bound(pi(p[i].x,i));
		if(it==s[y].end());else e[++m]=(node){i,it->se,d(i,it->se)};
		it=s[y].lower_bound(pi(p[i].x,i));
		if(it!=s[y].begin())it--,e[++m]=(node){i,it->se,d(i,it->se)};
	}sort(e+1,e+1+m);For(i,1,n)fa[i]=i;int c=0,ans=0;For(i,1,m){
		if(merge(e[i].u,e[i].v))c++,ans+=e[i].w;
		if(c==n-1)break;
	}cout<<ans<<endl;
	return 0;
}
