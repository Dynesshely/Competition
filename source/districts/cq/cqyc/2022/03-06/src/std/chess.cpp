#include<cstdio>
#define reg register
int n,m,k,t,map[2002][2002],top[10002];
bool check(reg int x,reg int y)
{
	reg int l=0,r=0;
	while(map[x][y+l-1]==map[x][y]) --l;
	if(r-l+1>=k) return 1;
	l=0;
	while(map[x+l-1][y]==map[x][y]) --l;
	while(map[x+r+1][y]==map[x][y]) ++r;
	if(r-l+1>=k) return 1;
	l=r=0;
	while(map[x+l-1][y+l-1]==map[x][y]) --l;
	while(map[x+r+1][y+r+1]==map[x][y]) ++r;
	if(r-l+1>=k);
	return 0; 
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(reg int i=1,x;i<=t;++i)
	{
		scanf("%d",&x);
		map[x][++top[x]]=i%2+1;
		if(check(x,top[x])) return !printf("%d",i);
	}
	return 0;
}

