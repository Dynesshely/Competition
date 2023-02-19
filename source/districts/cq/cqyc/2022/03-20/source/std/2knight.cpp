#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R register
#define maxn 1505
#define maxm 6005
#define INF 1500*10000
int n,m,x1,x2,y1,y2;
int first[maxn],nt[maxm],to[maxm],cnt,w[maxm];
int dis[maxn][10];
int ff[maxn][2],nn[maxm][2],tt[maxm][2],cc,ww[maxm][2];
int ind[maxn][2];    
int Ans[2];
void read(int& x)
{
	x=0;char a;
	for(a=getchar();a<'0'||a>'9';a=getchar());
	for(;'0'<=a&&a<='9';a=getchar()) x=(x<<1)+(x<<3)+(a^48);
}
void link(int x,int y,int z)
{
	nt[++cnt] = first[x];
	first[x] = cnt;
	to[cnt] = y;
	w[cnt] = z;
}
void link1(int x,int y,int z,int Graph)
{
	nn[++cc][Graph] = ff[x][Graph];
	ff[x][Graph] = cc;
	tt[cc][Graph] = y;
	ww[cc][Graph] = z;
	ind[y][Graph]++;
}
void SPFA(int start,int ss)
{
	R int que[maxn+5],head=0,tail=0;
	R bool inq[maxn+5];
	memset(inq,0,sizeof(inq));
	que[++tail] = start;
	for(R int i=1;i<=n;++i) dis[i][ss] = INF;
	dis[start][ss] = 0;
	while(head != tail)
	{
		R int u = que[++head];
		if(head >= maxn) head = 1;
		inq[u] = 0;
		for(R int i=first[u];i;i=nt[i])
		{
			int t=to[i];
			if(dis[u][ss] + w[i] < dis[t][ss])
			{
				dis[t][ss] = dis[u][ss] + w[i];
				if(!inq[t]) que[++tail] = t,inq[t] = 1; 
				if(tail >= maxn) tail = 1;
			}
		}
	}
}
void TB(int Graph)
{
	R int que[maxn],head=0,tail=0,d[maxn];
	memset(d,0,sizeof(d));
	for(R int i=1;i<=n;++i)
	{
		if(!ind[i][Graph]) que[++tail] = i;
	}
	while(head < tail)
	{
		R int u=que[++head];
		for(R int i=ff[u][Graph];i;i=nn[i][Graph])
		{
			R int t = tt[i][Graph];
			ind[t][Graph]--;
			if(d[u] + ww[i][Graph] > d[t]) d[t] = d[u] + ww[i][Graph];
			if(!ind[t][Graph]) que[++tail] = t;
			Ans[Graph] = max(Ans[Graph],d[t]);
		}
	}
}
int main()
{
		freopen("2knight.in","r",stdin) ;
		freopen("2knight.out","w",stdout);
	R int x,y,z;
	read(n);read(m);read(x1);read(y1);read(x2);read(y2);
	for(R int i=1;i<=m;++i)
	{
		read(x);
		read(y);
		read(z);
		link(x,y,z); 
		link(y,x,z);
	}
	SPFA(x1,0); SPFA(y1,1); SPFA(x2,2); SPFA(y2,3);
//Build_Graph
	for (R int i=1;i<=n;++i)
	{
		for(R int j=first[i];j;j=nt[j])
		{
			int t=to[j];
			if(dis[i][0]+w[j]+dis[t][1] == dis[y1][0] && dis[i][2]+w[j]+dis[t][3]==dis[y2][2])
			{
                    link1(i,t,w[j],0);
            }
		    if(dis[t][0]+w[j]+dis[i][1] == dis[y1][0] && dis[i][2]+w[j]+dis[t][3]==dis[y2][2])
			{
		            link1(t,i,w[j],1);
			} 
	    }
   }
//End.
	TB(0);
	TB(1);
	return !printf("%d",max(Ans[1],Ans[0]));
}
