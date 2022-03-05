#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
bool ppp;
const int N=25010;
void chmx(short &x,short y){(x<y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;
int mn[1000010];
unordered_map<int,short>mp;
char s[N];
	int idx=1;
	int nt[50000010][2];
	short res[50000010];
	void insert(int l,int r,short &val){
		int x=1;
		For(i,l,r){
			if(!nt[x][s[i]-'0'])nt[x][s[i]-'0']=++idx;
			x=nt[x][s[i]-'0'];
			chmx(res[x],val);
		}
		mp[x]=max(mp[x],val);
	}
short dp[N][330];
short ans;
bool pppp;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	freopen("war.in","r",stdin);
	freopen("war.out","w",stdout);
	n=read();scanf("%s",s+1);
	int qwe=0;For(i,0,400)qwe+=i,mn[qwe+1]=i+1;
	rep(i,n)if(!mn[i])mn[i]=mn[i-1];
	rep(i,n){
		short val=0;int x=1;
		For(j,i,min(i+320,n)){
			chmx(val,mp[x]);
			if(s[j]=='1')chmx(val,res[nt[x][0]]),x=nt[x][1];
			else x=nt[x][0];
			dp[j][j-i]=val+1;
			chmx(ans,val+1);
		}
		For(j,0,min(320,i-1)){
			if(mn[i-j]<j)break;
			insert(i-j,i,dp[i][j]);
		}
	}cout<<ans<<endl;
	return 0;
}




