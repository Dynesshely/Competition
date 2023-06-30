#include<bits/stdc++.h>
using namespace std;
int main(){
	short a,b;
	cin>>a>>b;
	if(a<60 && b<60){
		cout<<0;
	}else if(a<60 || b<60){
		cout<<1;
	}else{
		cout<<0;
	}
    return 0;
}
