#include<bits/stdc++.h>
#define reg register
int read()
{
	reg int s=0,f=1; reg char ch;
	for(;(ch=getchar())<'0'||ch>'9';ch=='-'?f=-f:0);
	for(;ch>='0'&&ch<='9';s=s*10+ch-'0',ch=getchar());
	return s*f;
}
int n,a[4][15],t[4][15];
std::string s;
int id(reg char c)
{
	if(c=='m') return 1;
	if(c=='p') return 2;
	if(c=='s') return 3;
}
char name(reg int x)
{
	if(x==1) return 'm';
	if(x==2) return 'p';
	if(x==3) return 's';
}
bool work()
{
	for(reg int i=1;i<=3;++i)
		for(reg int j=1;j<=11;++j)
			if(t[i][j]>0)
				t[i][j]%=3,t[i][j+1]-=t[i][j],t[i][j+2]-=t[i][j];
			else if(t[i][j]<0) return 0;
	return 1;
}
bool check()
{
	for(reg int i=1;i<=3;++i)
		for(reg int j=1;j<=9;++j)
			if(a[i][j]>=2)
			{
				memcpy(t,a,sizeof(a)),t[i][j]-=2;
				if(work()) return 1;
			}
	return 0;
}
void Main()
{
	for(reg int i=1;i<=3;++i)
		for(reg int j=1;j<=9;++j)
			if(a[i][j]<=3)
			{
				++a[i][j];
				if(check())
					putchar(j+'0'),putchar(name(i)),putchar(' ');
				--a[i][j];
			}
	puts("");
}
int main()
{
	freopen("mahjong.in","r",stdin);
	freopen("mahjong.out","w",stdout); 
	n=read();
	for(reg int t=read();t--;)
	{
		memset(a,0,sizeof(a));
		for(reg int i=1,x,c;i<=n;++i)
			std::cin>>s,x=s[0]-'0',c=id(s[1]),++a[c][x];
		if(n==14) putchar(check()+'0'),puts("");
		else Main();
	}
	return 0;
}
