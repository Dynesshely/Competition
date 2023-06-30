#include <bits/stdc++.h>
using namespace std;
int main(){
	string days[8]={"","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	int pop;
	cin>>pop;
	if(pop>0 && pop<=7){
		cout<<days[pop];
	}else{
		cout<<"input error!";
	}
	return 0;
}
