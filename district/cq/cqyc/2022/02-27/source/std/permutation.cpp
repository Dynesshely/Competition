#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
struct Point{
	double x,y;
	void init(){
		scanf("%lf%lf",&x,&y);
	}
	Point(double x=0.0,double y=0.0):x(x),y(y){}
	Point operator - (const Point p){
		return Point(x-p.x,y-p.y);
	}
	double operator * (const Point p){
		return fabs(x*p.y-y*p.x);
	}
}A[45];
inline double getArea(int i,int j,int k){
	return (A[i]-A[j])*(A[j]-A[k]);
}
inline bool inTriangle(int i,int j,int k,int x){
	return fabs(getArea(i,j,x)+getArea(j,k,x)+getArea(i,k,x)-getArea(i,j,k))<=1e-6;
}
inline void sort3(int& a,int& b,int& c){
	if(a>=b)	swap(a,b);
	if(a>=c)	swap(a,c);
	if(b>=c)	swap(b,c);
}
int N;
int hav[45][45][45];
long long dp[45][45][45][45];
const long long Md = 1e9 + 7;
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)	A[i].init();
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			for(int k=j+1;k<=N;k++)
				for(int l=1;l<=N;l++)
					if(l!=i && l!=j && l!=k)
						hav[i][j][k]+=inTriangle(i,j,k,l);
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			for(int k=j+1;k<=N;k++)
				dp[3][i][j][k]=6;
	for(int s=4;s<=N;s++)
		for(int i=1;i<=N;i++)
			for(int j=i+1;j<=N;j++)
				for(int k=j+1;k<=N;k++){
					if(hav[i][j][k]+4>=s)
						dp[s][i][j][k]=(dp[s-1][i][j][k]*(hav[i][j][k]+4-s))%Md;
					for(int l=1;l<=N;l++)
						if(l!=i && l!=j && l!=k && inTriangle(i,j,k,l)){
							int x,y,z;
							// i j l
							x=i,y=j,z=l;
							sort3(x,y,z);
							(dp[s][i][j][k]+=dp[s-1][x][y][z])%=Md;
							// j k l
							x=j,y=k,z=l;
							sort3(x,y,z);
							(dp[s][i][j][k]+=dp[s-1][x][y][z])%=Md;
							// i k l
							x=i,y=k,z=l;
							sort3(x,y,z);
							(dp[s][i][j][k]+=dp[s-1][x][y][z])%=Md;
						}
				}
	long long ans=0;
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			for(int k=j+1;k<=N;k++)
				(ans+=dp[N][i][j][k])%=Md;
	printf("%lld",ans);
	return 0;
}
