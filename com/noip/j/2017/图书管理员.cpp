#include <bits/stdc++.h>
using namespace std;

int pow(int num,int times){
	if(times==0 || times==1){
		return times==0 ? 1 : num;
	}
	int sum=1;
	for(int i=0;i<times;i++){
		sum*=num;
	}
	return sum;
}

int main()
{
	int n,q;
	cin>>n>>q;
	int books[n],requests[q][2];
	for(int i=0;i<n;i++){
		cin>>books[i];
	}
	for(int i=0;i<q;i++){
		cin>>requests[i][0]>>requests[i][1];
	}
	for(int i=0;i<q;i++){//遍历读者 
		int smallest=10000001;
		for(int j=0;j<n;j++){//遍历书 
			if((books[j]-requests[i][1])%pow(10,requests[i][0])==0){
				if(books[j]<smallest){
					smallest=books[j];
				}
			}
		}
		if(smallest!=10000001){
			cout<<smallest<<endl;
		}
		else{
			cout<<-1<<endl;
		}
		
	}
	return 0;
}
