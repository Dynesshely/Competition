#include <cstdio>
#define getc() getchar()
#define R register
#define L inline
#define ull unsigned long long
L ull Fastin()
{
	R char ch; R ull cnt = 0; R bool minus = 0;
	while (ch = getc(), (ch < '0' || ch > '9') && ch != '-') ;
	ch == '-' ? minus = 1 : cnt = ch - '0';
	while (ch = getc(), ch >= '0' && ch <= '9') cnt = cnt * 10 + ch - '0';
	return minus ? -cnt : cnt;
}
int main()
{
	
	freopen("output.in","r",stdin);
	freopen("output.out","w",stdout); 
	R int T=Fastin(),t,rec;
	R ull l,r,k,now;
	for (t=1;t<=T;++t)
	  {
	  	l=Fastin();
	    r=Fastin();
	    k=Fastin(); rec=1;
	    if (k==0) {
	    	if (l==0) printf("0 ");
	    	if (l<=1&&r>=1) printf("1 ");
	    	if (l>1) printf("None.");
		}
		else if (k==1){
			if (l<=1&&r>=1) printf("1");
			  else printf("None.");
		}
		else for (rec=0,now=1;now<=r;now*=k)
		  {
		  if (now>=l) printf("%llu ",now),rec=1;
		  if (now>r/k) break;
		  }
        if (!rec) printf ("None.");
        printf("\n");
	   } 
	   return 0;
}
