#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll int
using namespace std;
#define F(i,j,n)for(register int i=j;i<=n;i++)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
const int maxn = 5e5+5;
ll n,m,a[maxn],l,r;
long long sum[maxn];
short ans,now,p;
struct BIT{
	short c[505],ans;
	void clear(){F(i,1,p)c[i]=0;}
	void add(short pos,short val){for(;pos<=p;pos+=pos&-pos)(c[pos]<val)&&(c[pos]=val);}
	short query(short pos){ans=0;for(;pos;pos-=pos&-pos)(ans<c[pos])&&(ans=c[pos]);return ans;}
}bit;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout); 
	n=read();m=read();
	F(i,1,n)a[i]=read(),sum[i]=sum[i-1]+a[i];
	while(m--){
		l=read();r=read();p=read();
		if(r-l+1>p){puts("0");continue;}
		bit.clear();ans=1000;
		F(i,l,r){
			now=(sum[i]-sum[l-1])%p;ans=min(ans,now);
			if(ans==0)break;
			ans=min(ans,(short)(now-bit.query(now)));
			if(ans==0)break;
			bit.add(now,now);
		}
		printf("%hd\n",ans);
	}
	return 0;
}
