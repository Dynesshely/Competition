#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,y,left;
	cin>>n>>x>>y;
	if(y==0){
		cout<<n;
		return 0;
	}
	if(y/x>n){
		cout<<0;
		return 0;
	}
	left=n-y/x+(y%x==0?0:-1);
	cout<<left;
    return 0;
}
