#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main(){
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", (a * b) - a - b);
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//long long a, b, ans, ma, mb;
//int main(){
//	scanf("%lld %lld", &a, &b);
//	ma = max(a, b), mb = min(a, b);
//	long long arr[mb + 1][ma + 1];
//	bool sign[mb + 1][ma + 1];
//	memset(sign, true, sizeof(sign));
//	for(int i = 1, j = 1, index = 1; i <= mb && j <= ma; i = j == ma ? i + 1 : i, j = j == ma ? 1 : j + 1, index ++) arr[i][j] = index;
//	for(int i = 1; i <= mb; ++ i){
//		bool pass = true;
//		for(int j = 1; j <= ma; ++ j){
//			if(sign[i][j] && (arr[i][j] % a == 0 || arr[i][j] % b == 0)){
//				pass = false;
//				for(int k = i; k <= mb; ++ k) sign[k][j] = false;
//			}
//		}
//		if(pass) break;	
//	}
//	for(int i = mb, j = ma; i >= 1 && j >= 1; i = j == 1 ? i - 1 : i, j = j == 1 ? ma : j - 1)
//		if(sign[i][j]){
//			ans = arr[i][j];
//			break;
//		}
//	printf("%lld\n", ans);
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//int main() {
//	long a, b, row, col, fill = 1, big = 0, mmax;
//	scanf("%lld %lld", &a, &b);
//	row = min(a, b), col = max(a, b), mmax = a * b;
//	long _map[row][col];
//	const long length = 100000001;
//	bool *_list = new bool[length];
//	memset(_list, false, *_list + length);
//	for(int i = 0; i < row; ++ i){
//		for(int j = 0; j < col; ++ j) _map[i][j] = fill ++;
//	}
//	for(int i = 0; i <= mmax; ++ i){
//		for(int j = 0; j <= mmax; ++ j){
//			long long tmp = i * a + j * b;
//			if(tmp <= length) _list[tmp] = true;
//		}
//	}
//	for(int j = 0; j < col; ++ j){
//		for(int i = 0; i < row; ++ i){
//			if(_list[_map[i][j]]){
//				for(int k = i; k < row; ++ k) _map[k][j] = -1;
//				break;
//			}
//		}
//	}
//	delete _list;
//	for(int i = 0; i < row; ++ i){
//		for(int j = 0; j < col; ++ j) big = big > _map[i][j] ? big : _map[i][j];
//	}
//	printf("%lld\n", big);
//	return 0;
//}