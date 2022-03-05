#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,x,y,ans;
int f[520000],rd[520000],head[520000],dis[520000];
struct c{
    
	int to,next;
}a[550000];
int main()
{
    
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
    
		scanf("%d%d",&x,&y);
		a[i].to=y;
		a[i].next=head[x];
		head[x]=i;
		rd[y]++;
	}
	int h=0,t=0;
	for (int i=1;i<=n;i++)
	{
    
	    if (rd[i]==0)
	    {
    
	    	t++;
	    	f[t]=i;
	    }
	    dis[i]=1;
	}
	do{
    
		h++;
		for (int i=head[f[h]];i;i=a[i].next)
		{
    
			rd[a[i].to]--;
			dis[a[i].to]=max(dis[a[i].to],dis[f[h]]+1);
			if (rd[a[i].to]==0)
			{
    
				t++;
				f[t]=a[i].to;
			}
		}
	}while(h<t);
	for (int i=1;i<=n;i++)
	    cout<<dis[i]<<endl;
	return 0;
}