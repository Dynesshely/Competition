#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	double x,y;
	cin>>x>>y;
	/*
	j+t=x
	2j+4t=y
	j=x-t
	2(x-t)+4t=y
	2x-2t+4t=y
	2x+2t=y
	2t=y-2x
	t=(y-2x)/2
	j=x-t
	*/
	cout<<x-(y-2*x)/2<<" "<<(y-2*x)/2; 
	return 0;
} 
