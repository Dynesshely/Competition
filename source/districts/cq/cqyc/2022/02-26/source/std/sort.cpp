#include <bits/stdc++.h>
#define reg register
#define For(i,a,b) for(reg int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(reg int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(reg int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int T,n,k;
signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout); 
	T=1;
	while(T--){
		cin>>n>>k,k--;
		if(n<=61&&(1ll<<n-1)<=k){puts("-1");continue;}
		for(int i=1,r=1;i<=n;i=r+1,r=i){
			while(r<n&&n-r<=61&&(1ll<<n-r-1)&k)r++;
			Rof(j,r,i)printf("%lld ",j);
		}
		puts(""); 
	}
	return 0;
}
