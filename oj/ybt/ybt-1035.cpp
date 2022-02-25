#include<bits/stdc++.h>
using namespace std;
int now;
int getn(int a1,int d,int n){
	if(now!=n){
		now++;
		return getn(a1+d,d,n);	
	}else{
		return a1-d;
	}
}
int main(){
	int a1,a2,d,n;
	cin>>a1>>a2>>n;
	d=a2-a1;
	now=0;
	cout<<getn(a1,d,n);
    return 0;
}
