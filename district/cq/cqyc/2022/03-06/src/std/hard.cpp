#include<cstdio>
#include<cmath>
using namespace std;
int a[3005000],b[3005000],qa[10010],qb[10010],n,x;
bool va[3005000],vb[3005000];
long long ans=0;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int main(){
	freopen("hard.in","r",stdin);
	freopen("hard.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;++i) {
		++a[x=read()];
		if (!va[x]) va[x]=1,qa[++qa[0]]=x;
	}
	for (int i=0;i<n;++i) {
		++b[x=read()];
		if (!vb[x]) vb[x]=1,qb[++qb[0]]=x;
	}
	for (int i=1;i<=qa[0];++i) {
		for (int j=1;j<=qb[0];++j) {
			ans+=a[qa[i]]*1ll*b[qb[j]]*(long long)(sqrt(abs(qa[i]-qb[j])));
		}
	}
	printf("%lld",ans);
	return 0;
}
