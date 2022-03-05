#include<cstdio>
#define reg register
#define max(_a,_b) _a>_b?_a:_b
#define min(_a,_b) _a<_b?_a:_b
int R()
{
	reg int x=0;reg bool f=0;reg char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())if(ch=='-')f=1;
	for(;ch>=48&&ch<=57;ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
int main()
{
		freopen("meal.in","r",stdin) ;
		freopen("meal.out","w",stdout);
	reg int n=R(),i,x,maxn=0,minx=100000001;
	for(i=1;i<=n;++i) {
		x=R();
		minx=min(minx,x);
		maxn=max(maxn,x-minx);
	}
	printf("%d",maxn);
}
