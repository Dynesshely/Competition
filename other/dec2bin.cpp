#include <bits/stdc++.h>
using namespace std;
int main(){
	int dec,bins[100000],index=0;
	cin>>dec;
	while(dec){
		bins[index++]=dec%2;
		dec/=2;
	}
	for(int i=index-1;i>=0;i--){
		cout<<bins[i];
	}
	cout << endl;
	return 0;
}
