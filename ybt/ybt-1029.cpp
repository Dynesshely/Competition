#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b,r;
	int k;
	scanf("%lf%lf",&a,&b);
	k=a/b;
	r=a-k*b;
	printf("%g",r);
	return 0;
}
