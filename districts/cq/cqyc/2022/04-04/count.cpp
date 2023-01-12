#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int mod=998244353;
int n,m,fac[10000001],inv[10000001];
char buf[(1<<21)+5],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline int Mod(int x)
{
    return x>=mod? x-mod:x;
}
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
inline int c(int x,int y)
{
    if(x<0||y<0||x<y)
        return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    n=read(),m=read();
    fac[0]=inv[0]=1;
    for(int i=1;i<=n;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=pw(fac[n],mod-2);
    for(int i=n-1;i;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    while(m--)
    {
        vector<int> v;
        int k=read(),ans=0,d;
        v.resize(k+2);
        for(int i=1;i<=k;++i)
            v[i]=read();
        v[k+1]=n;
        d=read();
        ans=c(v[1],d);
        for(int i=1;i<=k;++i)
            ans=Mod(Mod(ans+c(v[i+1],d-i))-c(v[i],d-i-1)+mod);
        cout<<ans<<'\n';
    }
    return 0;
}
