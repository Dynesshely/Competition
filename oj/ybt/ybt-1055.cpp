#include <bits/stdc++.h>
using namespace std;
bool isLeap(int year){
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
int main(){
	int a;
	scanf("%d", &a);
	if(isLeap(a)){
		printf("Y\n");
	}else{
		printf("N\n");
	}
	return 0;
}
