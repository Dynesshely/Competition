#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define rep(i,n) For(i,0,(n)-1)
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
const int N=18,M=1<<N;
int n,a[N][N],to[N][N];char s[N];
#define lowbit(x) (x&-x)
int h[M][N];//h[S][u]: lowbit(S)->u
int f[M],g[M];
signed main(){
	freopen("gift.in","r",stdin);
	freopen("gift.out","w",stdout); 
	n=read();rep(i,n){
		rep(j,n){
			a[i][j]=read()-1;
			if(a[i][j]==i)For(k,0,j)to[i][a[i][k]]=1;
		}h[1<<i][i]=1;
	}int x;rep(S,1<<n){
		x=__builtin_ctz(lowbit(S));
//		print(S),cout<<"x = "<<x<<endl;
		rep(i,n)if((S>>i&1)&&h[S][i]){
			For(j,x,n-1)if(to[i][j]){
				if(!(S>>j&1))h[S|(1<<j)][j]+=h[S][i];
				else if(j==x)g[S]+=h[S][i];
			}
		}
	}
	f[0]=1;rep(S,1<<n){
		x=__builtin_ctz(lowbit(S));
		for(int T=S;T;(--T)&=S)
			if(T>>x&1)f[S]+=g[T]*f[S^T];
	}
	int q=read(),all=(1<<n)-1;while(q--){
		scanf("%s",s);int S=0;
		rep(i,n)if(s[i]=='H')S|=(1<<i);
		printf("%lld\n",f[S]*f[all^S]);
	}
	return 0;
}
