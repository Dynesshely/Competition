#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	double r;
	const double PI = 3.1416;
	cin>>r;
	printf("%0.4f %0.4f %0.4f",r*2,2*PI*r,PI*r*r);
	return 0;
} 
