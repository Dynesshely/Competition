#include <bits/stdc++.h>
using namespace std;
int m, n, tmp, sum = 0;
bool img1[110][110], img2[110][110];
int main(){
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m; ++ i)
		for(int j = 1; j <= n; ++ j){
			scanf("%d", &tmp);
			if(tmp) img1[i][j] = true;
			else img1[i][j] = false;
		}
	for(int i = 1; i <= m; ++ i)
		for(int j = 1; j <= n; ++ j){
			scanf("%d", &tmp);
			if(tmp) img2[i][j] = true;
			else img2[i][j] = false;
		}
	for(int i = 1; i <= m; ++ i)
		for(int j = 1; j <= n; ++ j)
			if(img1[i][j] == img2[i][j]) ++ sum;
	printf("%0.2f\n", sum * 1.0 * 100 / (m * n * 1.0));
	return 0;
}