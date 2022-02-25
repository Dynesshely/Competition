#include <bits/stdc++.h>
using namespace std;
int n, r, q[22];
void search(int now, int t){
	q[t] = now;
	if(t == r){
		for(int i = 1; i <= t; i++){
			printf("%3d", q[i]);
		}
		printf("\n");
		return;
	}
	for(int i = now + 1; i <= n; ++i){
		search(i, t + 1);
	}
	return;
}

int main(){
	scanf("%d %d", &n, &r);
	for(int i = 1; i <= n - r + 1; ++i){
		search(i, 1);
	}
	return 0;
}
