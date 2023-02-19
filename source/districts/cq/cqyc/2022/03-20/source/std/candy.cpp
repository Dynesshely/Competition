#include<iostream>
#include<cstdio>
#define reg register
using namespace std;
int R()
{
	reg int x=0;reg bool f=0;reg char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())if(ch=='-')f=1;
	for(;ch>=48&&ch<=57;ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
int ksm(reg int x,reg int n)
{
	reg int ans=1;
	while(n){
		if(n&1)ans=ans*x%10007;
		n>>=1;
		x=x*x%10007;
	}
	return ans;
}
int main()
{
		freopen("candy.in","r",stdin) ;
		freopen("candy.out","w",stdout);
	reg int q=R(),x=R(),i;
	for(i=1;i<=q;++i)printf("%d ",(ksm(2,R())*(x+2)-2)%10007);
	return 0;
}
