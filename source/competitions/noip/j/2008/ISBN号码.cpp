#include <bits/stdc++.h>
using namespace std;

int main()
{
	string isbn;
	cin>>isbn;
	int list[9]={isbn[0],isbn[2],isbn[3],isbn[4],isbn[6],isbn[7],isbn[8],isbn[9],isbn[10]},identeti=isbn[12],sum=0;
	for(int i=0;i<9;i++){
		list[i]-='0';
		sum+=list[i]*(i+1);
	}
	if(identeti == (sum%11 == 10 ? 'X' : sum%11 + '0')){
		cout<<"Right";
	}
	else{
		cout<<isbn[0]<<"-"<<isbn[2]<<isbn[3]<<isbn[4]<<"-"<<isbn[6]<<isbn[7]<<isbn[8]<<isbn[9]<<isbn[10]<<"-";
		if(sum%11==10){
			cout<<"X"; 
		}else{
			cout<<sum%11;
		}
	}
	return 0;
}
