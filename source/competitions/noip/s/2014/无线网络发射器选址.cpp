#include <bits/stdc++.h> 
using namespace std;
int _map[200][200], maxn, maxi, d, n, i, j, x, y, k, m, ans;
int main(){
    scanf("%d", &d);  
    memset(_map, 0, sizeof(_map));
    scanf("%d", &n);
    for (i = 1; i <= n; ++ i){
		scanf("%d %d %d", &x, &y, &k);
		_map[x][y] = k;
	}
    maxn = 0, maxi = 0;
    for(i = 0, j = 0; i <= 128 && j <= 128; i = j == 128 ? i + 1 : i, j = j == 128 ? 0 : j + 1){
		ans = 0;
		for(k = max(0, i - d); k <= min(128, i + d); ++ k)
        	for(m = max(0, j - d); m <= min(128, j + d); ++ m)
          		ans += _map[k][m];
      	if(ans == maxn) maxi++;
      	if(ans > maxn){ maxn = ans; maxi = 1; }	
	}
    printf("%d %d\n", maxi, maxn);
    return 0;  
}