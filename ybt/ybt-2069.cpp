#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	a=a/3;b=b+a;e=e+a;
	b=b/3;c=c+b;a=a+b;
	c=c/3;d=d+c;b=b+c;
	d=d/3;e=e+d;c=c+d;
	e=e/3;a=a+e;d=d+e;
	cout<<setw(5)<<a<<setw(5)<<b<<setw(5)<<c<<setw(5)<<d<<setw(5)<<e; 
} 

