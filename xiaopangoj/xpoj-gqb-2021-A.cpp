#include <bits/stdc++.h>
using namespace std;
int A, B, C;
int main(){
	scanf("%d %d %d", &A, &B, &C);
	int tmp = B, tmp2 = C;
	B = A; A = tmp; C = A; A = tmp2;
	printf("%d %d %d\n", A, B, C);
	return 0;
}