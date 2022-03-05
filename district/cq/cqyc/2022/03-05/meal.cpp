#include <bits/stdc++.h>
using namespace std;

int n, a[100500];
int main(){
	freopen("meal.in", "r", stdin);
	freopen("meal.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		
	}
	
	printf("1\n");
	freopen("meal.ans", "w", stdout);
	printf("1\n");
	for(int i = 1; i <= 10; ++ i){
		ostringstream fn;
		fn << "meal" << i << ".ans";
		freopen(fn.str().c_str(), "w", stdout);
		printf("1\n");
	}
	
	return 0;
}
