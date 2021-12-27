#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,count=0;
	cin>>n;
	long long nums[n];
	for(long long i=0;i<n;i++){
		cin>>nums[i];
	}
	sort(nums,nums+n);
	for(long long i=2;i<n;i++){
		int flag=false;
		for(long long j=0;j<i-1;j++){
			for(long long p=j+1;p<i;p++){
				if(nums[j] + nums[p] == nums[i]){
					count++;
					flag=true;
					//printf("%d + %d = %d\n",nums[j],nums[p],nums[i]);
					break;
				}
			}
			if(flag){
				break;
			}
		}
	}
	cout<<count;
	return 0;
}
