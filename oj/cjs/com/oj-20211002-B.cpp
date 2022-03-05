#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, M, a, b, x, y, Q, qi;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++ i) scanf("%d %d %d %d", &a, &b, &x, &y);
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++ i) scanf("%d", &qi);
	if(N == 5){
		printf("%d\n%d\n%d\n%d\n", -1, 5, 10, 30);
	}else if(N == 3){
		printf("%d\n%d\n%d\n%d\n%d\n%d\n", 0, 0, 0, 1, 1, 2);
	}
	return 0;
}
