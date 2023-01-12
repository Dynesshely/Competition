#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define pb push_back
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e3+10;
int a[N],to[N][N],vis[N],n;
vector<int> g[N];priority_queue<int> q;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
void dfs(int u){
	vis[u]=1;
	For(v,1,n)if(!vis[v]&&to[u][v])g[u].pb(v),dfs(v);
}
void topo(){
	while(!q.empty()){
		int u=q.top();q.pop();
		printf("%d ",a[u]);
		for(int v:g[u])q.push(v);
	}
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout); 
	n=read();For(i,1,n)a[i]=read();sort(a+1,a+1+n);
	For(i,1,n)For(j,1,i-1)if(gcd(a[i],a[j])!=1)to[i][j]=to[j][i]=1;
	For(i,1,n)if(!vis[i])dfs(i),q.push(i);topo();
	return 0;
}
