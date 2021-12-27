#include <bits/stdc++.h>
using namespace std;
int n, maxl, ls = 0;
string strs[20];
int main(){
	scanf("%d", &n); maxl = n * 2 - 1;
	for(int i = 1; i <= n; ++ i){
		++ ls;
		for(int j = 1; j <= (maxl - (i * 2 - 1)) / 2; ++ j)
			strs[ls] += ' ';
		for(int j = 1; j <= i * 2 - 1; ++ j)
			if('0' + j <= '0' + 9)
				strs[ls] += '0' + j;
			else{
				strs[ls] += '0' + 1;
				strs[ls] += '0' + j - 10;
			}
		for(int j = 1; j <= (maxl - (i * 2 - 1)) / 2; ++ j)
			strs[ls] += ' ';
	}
	for(int i = 1; i <= ls; ++ i)
		cout << strs[i] << endl;
	for(int i = ls - 1; i > 0; -- i)
		cout << strs[i] << endl;
	return 0;
}