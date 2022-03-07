#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
 
typedef long long ll;
ll mod,m;
 
inline void update(ll &a,const ll &b)
{
	a+=b;if (a>mod) a-=mod;
}
 
inline ll mul(ll a,ll b)
{
	ll now=a,ret=0;
	while (b)
	{
		if (b&1) update(ret,now);
		update(now,now);
		b>>=1;
	}
	return ret;
}
 
inline ll fp(ll a,ll x)
{
	ll ret=1,now=a;
	while (x)
	{
		if (x&1) ret=mul(ret,now);
		now=mul(now,now);x>>=1;
	}
	return ret;
}
 
int main()
{
	freopen("beauty.in","r",stdin);
	freopen("beauty.out","w",stdout);
	int T;
	cin>>T;
	while (T--)
	{
		scanf("%lld%lld",&mod,&m);
		if (mod==2) cout<<1<<endl;
			else cout<<fp((1+4*(mod-m))%mod,(mod-1)/2)<<endl;
	}
	return 0;
}
