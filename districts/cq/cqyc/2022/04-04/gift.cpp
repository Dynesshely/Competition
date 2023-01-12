#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN 20
int n;
struct data{double x,y;} a[MAXN];
double v;
int bin[MAXN];
double dis[MAXN][MAXN],f[200000];
#define sqr(x) ((x)*(x))
inline void cmin(register double &x,register double y) {x>y?x=y:0;}
int main()
{
		freopen("gift.in","r",stdin);
		freopen("gift.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<=n;i++) scanf("%lf %lf",&a[i].x,&a[i].y);
	scanf("%lf",&v);
	bin[1]=1;for(int i=2;i<=n+1;i++) bin[i]=bin[i-1]<<1;
	for(int i=0;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			dis[i][j]=sqrt(sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y))/v;
	memset(f,70,sizeof(f));
	f[0]=0.0;
	for(register int i=0;i<bin[n+1];i++)
		for(register int g1=1;g1<=n;g1++)
			if((i|bin[g1])>i)
			{
				cmin(f[i|bin[g1]],f[i]+dis[0][g1]*3);
				for(register int g2=g1+1;g2<=n;g2++)
					if((i|bin[g2])>i)
						cmin(f[i|bin[g1]|bin[g2]],f[i]+(dis[0][g1]<dis[0][g2]?(dis[0][g1]*4+dis[0][g2]):(dis[0][g1]+dis[0][g2]*4))+dis[g1][g2]*2);
			}
	printf("%.0lf\n",f[bin[n+1]-1]);
	return 0;
}
