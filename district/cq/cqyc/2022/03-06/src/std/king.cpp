#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,q,a[500010];
bool set[2000010];
long long lazy[2000010],ans[500010],sum[2000010],now;
struct question{
	int opt,x,y,z;
}Q[500010];
void clear(int k){
	lazy[k]=sum[k]=0;
	set[k]=1;
}
void in(int l,int r,int k,long long v){
	sum[k]+=1ll*v*(r-l+1);
	lazy[k]+=v;
}
void down(int l,int r,int mid,int k){
	if(set[k]){
		clear(k<<1);
		clear(k<<1|1);
		set[k]=0;
	}
	if(lazy[k]){
		in(l,mid,k<<1,lazy[k]);
		in(mid+1,r,k<<1|1,lazy[k]);
		lazy[k]=0;
	}
}
void find(int l,int r,int x,int y,int k){
	if(x>r||y<l)return;
	if(l>=x&&r<=y){
		now+=sum[k];
		clear(k);
		return;
	}
	int mid=(l+r)>>1;
	down(l,r,mid,k);
	find(l,mid,x,y,k<<1);
	find(mid+1,r,x,y,k<<1|1);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
void add(int l,int r,int x,int y,long long z,int k){
	if(x>r||y<l)return;
	if(l>=x&&r<=y){
		in(l,r,k,z);
		return;
	}
	int mid=(l+r)>>1;
	down(l,r,mid,k);
	add(l,mid,x,y,z,k<<1);
	add(mid+1,r,x,y,z,k<<1|1);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int stk[30],tp;
void write(long long x){
	do stk[++tp]=x%10,x/=10;while(x);
	while(tp)putchar(stk[tp--]^48);
}
int main(){
	freopen("king.in","r",stdin);
	freopen("king.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=q;i++)Q[i].opt=read(),Q[i].x=read(),Q[i].y=read(),Q[i].z=read(); 
	for(int i=q;i>=1;i--){
		if(Q[i].opt==1)now=0,find(1,n,Q[i].x,Q[i].y,1),ans[Q[i].z]+=now;
		else add(1,n,Q[i].x,Q[i].y,(long long)Q[i].z,1);
	}
	for(int i=1;i<=n;i++)if(a[i])now=0,find(1,n,i,i,1),ans[a[i]]+=now;
	for(int i=1;i<=m;i++)write(ans[i]),putchar('\n');
	return 0;
}
