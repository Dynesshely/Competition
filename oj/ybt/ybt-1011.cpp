#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	double a,b;
	//a-È·ÕïÊý b-ËÀÍöÊý 
	cin>>a>>b;
	double c=b/a;
	printf("%0.3f%%",c*100);
	/* 
	ostringstream myos;
	myos<<c;
	string d=myos.str();
	cout<<"0.";
	for(int i=0;i<3;i++)
	{
		cout<<d[i+4];
	}
	cout<<"%";
	*/
	return 0;
} 
