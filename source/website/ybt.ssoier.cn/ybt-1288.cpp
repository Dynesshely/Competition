#include <bits/stdc++.h>
using namespace std;
int n, _map[100][100], m;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= i; ++j){
			scanf("%d", &_map[i][j]);
			_map[i][j]=max(_map[i-1][j],_map[i-1][j-1])+_map[i][j];
		}
	}
	for(int i = 1; i <= n; ++i){
		m = max(m, _map[n][i]);
	}
	printf("%d\n", m);
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//int n, _map[100][100], _flag[101][100], _flag2[101][100], max = 0;
//int main(){
//	scanf("%d", &n);
//	for(int i = 0; i < n; ++i){
//		for(int j = 0; j <= i; ++j){
//			scanf("%d", &_map[i][j]);
//			if(i != 0){
//				int fm = _map[i][j], rm = _flag2[i-1][j-1] + fm, um = _flag[i-1][j] + fm;
//				_flag[i][j] = um > rm ? um : rm;
//				_flag2[i][j] = um > rm ? um : rm;
//			}
//		}
//	}
//	for(int i = 0; i < 100; ++i){
//		max = _flag[n-1][i] > max ? _flag[n-1][i] : max;
//		max = _flag2[n-1][i] > max ? _flag2[n-1][i] : max;
//	}
//	printf("%d\n", max);
//	return 0;
//}
