#include<cstdio>
#define reg register
int p[10002];
int R()
{
	reg int x=0;reg bool f=0;reg char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())if(ch=='-')f=1;
	for(;ch>=48&&ch<=57;ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
void write(reg int x)
{
	if(x>9)write(x/10);
	putchar(x%10^48); 
}
void W1(reg int x)
{
	if(x<0)putchar('-'),x=0-x;
	if(x>1)write(x);
}
void W2(reg int x)
{
	if(x>1)putchar('^'),write(x);
}
int main()
{
	freopen("poly.in","r",stdin);
	freopen("poly.out","w",stdout);
	reg int n=R(),i;
	for(i=n;i>=0;--i)p[i]=R();
	for(i=n;i;--i){
		if(p[i])W1(p[i]),putchar('x'),W2(i);
		if(p[i-1]>0)putchar('+');
	}
	printf("%d",p[0]);
}
