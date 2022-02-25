/*
	贵青杯赛事题或者训练题
*/

#include <bits/stdc++.h>
using namespace std;
int n, sum = 0;
double tmp;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i){
		cin >> tmp;
		if(tmp > 90 && tmp < 140) ++ sum;
		else sum = 0;
	}
	printf("%d\n", sum);
	return 0;
}