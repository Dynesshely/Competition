#include <cstdio>
#include <cstring>
#define reg register
#define max(_a,_b) (_a>_b?_a:_b)
const int N=1000002,S=2000002;
char s[N];
int R()
{
	reg int x=0;reg bool f=0;reg char ch=getchar();
	for(;ch<48||ch>57;ch=getchar()) f=ch=='-';
	for(;ch>=48&&ch<=57;ch=getchar()) x=x*10+ch-48;
	return f?-x:x;
}
int main()
{
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout); 
	reg int T=R(),len,i,ans,k1,k2,at,tat;
	while(T--) {
		gets(s+1);
		len=strlen(s+1),ans=k1=k2=at=tat=0;
		for(i=len;i;--i) {
			if(s[i]=='A') {
				if(k2) --k2,++at;
				else if(k1<tat) ++k1;
			}
			else if(s[i]=='T') {
				if(at) --at,++ans,++tat;
				else {
					++k2;
					if(tat&&k1) --k1,--k2,++at;
				}
			}
			else if(s[i]=='C') {
				if(at) --at,++ans;
				else if(tat) {
					--tat,++k2;
					if(k1) --k1,--k2,++at;
				}
			}
		}
		printf("%d\n",ans);
	}
}
