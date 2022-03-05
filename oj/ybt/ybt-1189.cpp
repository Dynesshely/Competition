#include <bits/stdc++.h>
using namespace std;
unsigned long long pell[1000001];
double getpell(long long i){
	return ((sqrt(2) + 2) / 4) * pow((1 + sqrt(2)), i - 1) + ((sqrt(2) - 2) / 4) * pow((1 - sqrt(2)), i - 1);
}
int main(){
//	int n;
//	scanf("%d", &n);
//	pell[1] = 1, pell[2] = 2;
//	for(int i = 3; i <= 1000000; ++ i){
//		pell[i] = 2 * pell[i - 1] + pell[i - 2];
//	}
//	for(int i = 0; i < n; ++ i){
//		int tmp;
//		scanf("%d", &tmp);
//		long long rst = pell[tmp] % 32767;
//		printf("%lld\n", rst);
//	}
	int n;
	scanf("%d", &n);
	int ids[n] = {};
	for(int i = 0; i < n; ++ i){
		scanf("%d", &ids[i]);
	}
	for(int i = 0; i < n; ++ i){
		printf("%d\n", (int)round(getpell(ids[i])) % 32767);
	}
	return 0;
}