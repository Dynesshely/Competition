#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
bool ppp;
const int N=1e7+7;
const int inf=1e9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,k,len;
char s[N];
int a[N],A[N];
int b[N];
int q[4];
int upd(int x){return x>k?x-k:(x<0?x+k:x);}
bool pppp;
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	k=read();scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,n){
		if(s[i]==s[i-1])continue;
		a[++len]=(s[i]=='0'?0:'0'+k-s[i]);
	}
	rep(i,len)A[i]=A[i-1]+upd(a[i]-a[i-1]);
	rep(i,len)b[i]=A[i]/k;
//	rep(i,len)cout<<a[i]<<" ";return 0;
	int res=0;
	Rof(i,len,1){
		q[upd(a[i]-a[i-1])]++;
		if(b[i]>b[i-1])Rof(j,k-1,1)if(q[j]){q[j]--;res+=j;break;}
	}
	cout<<A[len]-res<<endl;
	return 0;
}
