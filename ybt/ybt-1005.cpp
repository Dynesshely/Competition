#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x,y,a,b,hold;
	cin>>x>>a>>y>>b;
	hold=(b*y-a*x)*1.0/(1.0*(b-a));
	printf("%0.2f",hold);
	return 0;
}
