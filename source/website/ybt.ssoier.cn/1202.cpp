#include <bits/stdc++.h>
using namespace std;
int n;
long long got[1000010], k[1000010];
long long get(int n){
	if(got[n] != 0){
		return got[n];
	}else{
		got[n] = (2 * get(n - 1) + get(n - 2)) % 32767;
	}
}
void init(){
	got[1] = 1;
	got[2] = 2;
	for(int i = 3; i < 1000010; ++i){
		get(i);
	}
}
int main(){
	init();
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		cin >> k[i];
	}
	for(int i = 0; i < n; ++i){
		cout << got[k[i]] << endl;
	}
	return 0;
}
