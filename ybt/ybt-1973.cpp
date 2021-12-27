#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long n,price[3],nums[3],min[3];
	cin>>n;
	for(int i=0;i<3;i++){
		cin>>nums[i]>>price[i];
		if(n%nums[i]==0){
			min[i]=n/nums[i]*price[i];
		}else if(n<nums[i]){
			min[i]=price[i];
		}else{
			min[i]=(n/nums[i]+1)*price[i];
		}
	}
	sort(min,min+3);
	cout<<min[0];
	return 0;
}
