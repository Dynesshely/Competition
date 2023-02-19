#include<cstdio>
using namespace std;
int w,s,n;
int q[2010];
double v[2010];
double dp[2010];
double maxt;
int nw;
int main()
{
		freopen("coffee.in","r",stdin) ;
		freopen("coffee.out","w",stdout);
	int i,j;
	scanf("%d%d%d",&w,&s,&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%lf",q+i,v+i);
		v[i]=(double)s/v[i];
	}
	for(i=1;i<=n;++i)
	{
		dp[i]=10000000;
		nw=q[i];
		maxt=v[i];
		for(j=i-1;j>=0&&nw<=w;--j)
		{
			if(dp[i]>dp[j]+maxt)
				dp[i]=dp[j]+maxt;
			nw+=q[j];
			if(maxt<v[j])
				maxt=v[j];
		}
	}
	printf("%.2lf\n",dp[n]);
	return 0;
}
