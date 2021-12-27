#include <iostream>
using namespace std;
int main()
{
	double dis;
	cin>>dis;
	double bike = 27 + 23 + dis/3.0, walk = dis/1.2;
	if(bike<walk){
		cout<<"Bike";
	}else if(bike>walk){
		cout<<"Walk";
	}else{
		cout<<"All";
	}
    return 0;
}
