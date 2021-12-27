#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	int b=a/100,c=a/10%10,d=a%10;
	if(a<0){
		b=abs(b);
		c=abs(c);
		d=abs(d);
		//cout<<"-";
	}
	int n=d*100+c*10+b;
	cout<<n;
	return 0;
} 

