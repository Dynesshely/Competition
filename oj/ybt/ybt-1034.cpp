#include<bits/stdc++.h>
using namespace std;
double distance(double xa,double ya,double xb,double yb){
    return sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya));
}
int main(){
	double x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1;
	cin>>x2>>y2;
	cin>>x3>>y3;
	double a,b,c;
	a=distance(x1,y1,x2,y2);
	b=distance(x2,y2,x3,y3);
	c=distance(x1,y1,x3,y3);
	double p=(a+b+c)/2;
	printf("%0.2f",sqrt(p*(p-a)*(p-b)*(p-c)));
    return 0;
}
