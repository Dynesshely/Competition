#include <bits/stdc++.h>
using namespace std;
int main(){
	double width,pricel=1.68,priceb=1.98;
	cin>>width;
	if(width<=20.0){
		printf("%0.2f",width*pricel);
	}else{
		printf("%0.2f",width*priceb);
	}
	return 0;
}
