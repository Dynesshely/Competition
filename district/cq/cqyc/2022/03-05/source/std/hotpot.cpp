#include<bits/stdc++.h>
#define IL inline
#define RE register
#define N 300300
#define getchar() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?EOF:*S++)
char B[1<<15],*S=B,*T=B;
IL int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+(ch^48),ch=getchar();
	return x;
}

int n,m,rt;
int first[N],nxt[N<<1],to[N<<1],num;

IL void add(int u,int v){nxt[++num]=first[u],to[num]=v,first[u]=num;}

IL void add_edge(int u,int v){add(u,v),add(v,u);}

int fa[N],dep[N],size[N],son[N];

void dfs1(int u)
{
	size[u]=1,dep[u]=dep[fa[u]]+1;
	for(RE int i=first[u],v;i;i=nxt[i])if(!size[v=to[i]])
		fa[v]=u,dfs1(v),size[u]+=size[v],size[son[u]]<size[v]?son[u]=v:0;
}

int top[N];

void dfs2(int u,int rt)
{
	top[u]=rt;
	if(son[u])dfs2(son[u],rt);
	for(RE int i=first[u],v;i;i=nxt[i])if(!top[v=to[i]])dfs2(v,v);
}

IL void swap(int &x,int &y){x^=y^=x^=y;}

IL int lca(int x,int y)
{
	for(;top[x]^top[y];x=fa[top[x]])if(dep[top[x]]<dep[top[y]])swap(x,y);
	return dep[x]>dep[y]?y:x;
}

long long ans;
int f[N];

void solve(int u)
{
	for(RE int i=first[u],v;i;i=nxt[i])if((v=to[i])^fa[u])
		solve(v),f[u]+=f[v]; 
	if(!f[u])ans+=m;
	else if(f[u]<2)++ans;
}

int main()
{
//	system("fc hotpot.out hotpot2.ans");
		freopen("hotpot.in","r",stdin) ;
		freopen("hotpot.out","w",stdout);
	srand(time(NULL)); 
	n=read(),m=read();
	rt=rand()%n+1;
	for(RE int i=1;i<n;++i)add_edge(read(),read());
	dfs1(rt),dfs2(rt,rt);
	for(RE int i=1;i<=m;++i)
	{
		int x=read(),y=read(),fa=lca(x,y);
		++f[x],++f[y],f[fa]-=2;
	}
	solve(rt);
	return printf("%lld",ans-m),0;
} 
