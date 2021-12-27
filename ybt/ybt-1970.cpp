#include <bits/stdc++.h>
using namespace std;
int main()
{
	//*-42 ?-63
	int n,m;
	const int boomSign = 42;
	cin>>n>>m;
	int map[n][m],nums[n][m];
	for(int i=0;i<n;i++){
		string line;
		cin>>line;
		for(int j=0;j<m;j++){
			map[i][j]=line[j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i>0 && i<n-1 && j>0 && j<m-1){
				if(map[i][j]!=boomSign){
					int l=j-1,r=j+1,u=i-1,d=i+1;
					int boom=0,xs[8]={u,u,u,i,i,d,d,d},ys[8]={l,j,r,l,r,l,j,r};
					for(int q=0;q<8;q++){
						if(map[ys[q]][xs[q]]==boomSign){
							boom++;
						}
					}
					nums[i][j]=boom;
				}else{
					nums[i][j]=boomSign;
				}
			}
		}
	}
	for(int j=1;j<m-1;j++){
		int boom_0=0,boom_n1=0,left=j-1,right=j+1,end=n-1,endsnd=n-2;
		if(map[0][left]==boomSign){boom_0++;}
		if(map[0][right]==boomSign){boom_0++;}
		if(map[1][left]==boomSign){boom_0++;}
		if(map[1][j]==boomSign){boom_0++;}
		if(map[1][right]==boomSign){boom_0++;}
		nums[0][j]=boom_0;
		if(map[end][left]==boomSign){boom_n1++;}
		if(map[end][right]==boomSign){boom_n1++;}
		if(map[endsnd][left]==boomSign){boom_n1++;}
		if(map[endsnd][j]==boomSign){boom_n1++;}
		if(map[endsnd][right]==boomSign){boom_n1++;}
		nums[end][j]=boom_n1;
	}
	// (0,0) (m-1,0) (0,n-1) (m-1,n-1)
	int xs[12]={0,1,1,m-2,m-1,m-2,0,1,1,m-1,m-2,m-2}, ys[12]={1,0,1,0,1,1,n-2,n-2,n-1,n-2,n-2,n-1};
	int boom_0=0,boom_1=0,boom_2=0,boom_3=0;
	for(int i=0;i<12;i++){
		if(map[ys[i]][xs[i]]==boomSign){
			if(i<3){
				boom_0++;
			}else if(i<6){
				boom_1++;
			}else if(i<9){
				boom_2++;
			}else{
				boom_3++;
			}
		}
	}
	nums[0][0]=boom_0;
	nums[0][m-1]=boom_1;
	nums[n-1][0]=boom_2;
	nums[n-1][m-1]=boom_3;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(nums[i][j]==boomSign){
				cout<<"*";
			}else{
				cout<<nums[i][j];
			}
			cout<<(j==m-1?"\n":" ");
		}
	}
	return 0;
}
