#include <bits/stdc++.h>
using namespace std;
void solve(long long nn, list<long long> &ls){
	long long closest=2, index=1;
	while(nn>closest){
		closest*=2;
		index++;
	}
	if(closest != nn){
		closest/=2;
		ls.push_back(closest);
		long long left = nn - closest;
		solve(left, ls);
	}else{
		ls.push_back(nn);
	}
}

int main(){
	long long nn, chais[100000];
	scanf("%lld", &nn);
	//nn=4294967294;
	list<long long> ls;
	if(nn % 2){
		cout<<-1;
		return 0;
	}else{
		solve(nn, ls);
	}
	list<long long>::iterator p1; 
	for(p1=ls.begin();p1!=ls.end();p1++){
		cout<< *p1 <<" ";
	}
	cout << endl;
	return 0;
}
