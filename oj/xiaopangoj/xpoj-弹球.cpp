/*
	贵青杯赛事题或者训练题
*/

#include <bits/stdc++.h>
using namespace std;
double m, n, nh = 0, path = 0;
int main(){
	cin >> m >> n;
	nh = m;
	for(int i = 1; i <= n; ++ i){
		path += 1.5 * nh;
		nh /= 2;
	}
	printf("%0.2f %0.2f\n", nh, path);
	return 0;
}