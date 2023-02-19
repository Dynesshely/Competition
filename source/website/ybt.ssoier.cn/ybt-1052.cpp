#include <bits/stdc++.h>
using namespace std;
int main()
{
	int mess,price;
	char type;
	cin>>mess>>type;
	if(mess<=1000){
		price=8;
	}else if(mess > 1000){
		price = 8 + ((mess - 1000) / 500 + ((mess - 1000) % 500 == 0 ? 0 : 1)) * 4;
	}
	if(type=='y'){
		price+=5;
	}
	cout<<price;
    return 0;
}
