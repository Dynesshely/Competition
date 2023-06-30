#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n==0){
		cout<<1;
		return 0;
	}
	unsigned long long sum = 2;
	for(int i=0;i<n-1;i++){
		sum*=2;
	}
	cout<<sum;
    return 0;
}
