#include <bits/stdc++.h>
using namespace std;
int main(){
	double r1, r2, temp;
	cin >> r1 >> r2;
	temp = min(r1, r2), r1 = max(r1, r2), r2 = temp;
	printf("%d\n", (int)(3.14 * r1 * r1 - 3.14 * r2 * r2));
	return 0;
}