#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b,c,s,p;
	cin>>a>>b>>c;
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%0.3f",s);
	return 0;
}
