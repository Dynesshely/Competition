#include <bits/stdc++.h>
using namespace std;
int main()
{
	double N,y;
	cin>>N;
	if(N>=0 && N<5){
		y=2.5-N;
	}else if(N>=5 && N<10){
		y=2-1.5*(N-3)*(N-3);
	}else if(N>=10 && N<20){
		y=N/2-1.5;
	}
	printf("%0.3f",y);
    return 0;
}
