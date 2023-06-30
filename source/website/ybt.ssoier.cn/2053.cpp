#include <bits/stdc++.h>
using namespace std;
int main(){
	int ints[3];
	for(int i=0;i<3;i++){
		cin>>ints[i];
	}
	sort(ints,ints+3);
	for(int i=2;i>=0;i--){
		cout<<ints[i]<<" ";
	}
	return 0;
}
