#include <bits/stdc++.h>
using namespace std;
long long Q, tmp;
queue<long long> quiry;
int main(){
	scanf("%d", &Q);
	for(long long i = 0; i < Q; ++ i){
		scanf("%lld", &tmp);
		quiry.push(tmp);
	}
//	for(long long i = 0; i < Q; ++ i){
//		long long a = quiry.front();
//		printf("%lld\n", a);
//		quiry.pop();
//		quiry.push(a);
//	}
	
	return 0;
}