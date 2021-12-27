#include <bits/stdc++.h>
using namespace std;
int M, N, sum = 0;
int main(){
	scanf("%d %d", &M, &N);
	for(int i = 1; i <= N; ++ i){
		int tmp;
		scanf("%d", &tmp);
		if(M > tmp) ++ sum;
	}
	printf("%d\n", sum);
	return 0;
}